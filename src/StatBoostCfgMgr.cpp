#include "StatBoostCfgMgr.h"

StatBoosterConfig* StatBoosterConfig::GetInstance()
{
    if (!instance)
    {
        instance = new StatBoosterConfig();
    }

    return instance;
}

void StatBoosterConfig::EnchantPool::Add(EnchantDefinition definition)
{
    pool.push_back(definition);
}

EnchantDefinition* StatBoosterConfig::EnchantPool::Get(uint32 roleMask, uint32 classMask, uint32 subClassMask, uint32 itemLevel)
{
    std::shuffle(std::begin(pool), std::end(pool), randomEngine);
    LOG_INFO("module", ">> Trying to get enchant with role mask {}, classMask {}, subClassMask {}, and itemlevel {} from pool.", roleMask, classMask, subClassMask, itemLevel);

    if (roleMask == 0 && classMask == 0 && subClassMask == 0)
    {
        uint32 randItem = urand(0, (sizeof(pool) / sizeof(pool[0])));
        return &pool[randItem];
    }

    auto iterator = std::find_if(pool.begin(), pool.end(), [&](const EnchantDefinition& data)
    {
            return ((data.RoleMask & roleMask) == roleMask || data.RoleMask == 0) &&
                ((data.ClassMask & classMask) == classMask || data.ClassMask == 0) &&
                ((data.SubClassMask & subClassMask) == subClassMask || data.SubClassMask == 0) &&
                (itemLevel >= data.ILvlMin && itemLevel <= data.ILvlMax);
    });

    if (!(iterator == pool.end()))
    {
        return &(*iterator);
    }

    return 0;
}

bool StatBoosterConfig::EnchantPool::Load()
{
    try
    {
        QueryResult qResult = WorldDatabase.Query("SELECT Id, iLvlMin, iLvlMax, RoleMask, ClassMask, SubClassMask FROM statbooster_enchant_template");

        if (!qResult)
        {
            LOG_INFO("module", "Failed to load StatBooster enchant definitions from 'statbooster_enchant_template' table.");
            return;
        }

        LOG_INFO("module", "Loading StatBooster enchants from 'statbooster_enchant_template' table.");

        sBoostConfigMgr->EnchantPool.Clear();

        do
        {
            Field* fields = qResult->Fetch();

            EnchantDefinition enchantDef;

            enchantDef.Id = fields[0].Get<uint32>();
            enchantDef.ILvlMin = fields[1].Get<uint32>();
            enchantDef.ILvlMax = fields[2].Get<uint32>();
            enchantDef.RoleMask = fields[3].Get<uint32>();
            enchantDef.ClassMask = fields[4].Get<uint32>();
            enchantDef.SubClassMask = fields[5].Get<uint32>();

            sBoostConfigMgr->EnchantPool.Add(enchantDef);
            LOG_INFO("module", ">> Loaded Enchant ID {} with role mask {}, class mask {}, and subclass mask {} into enchant pool.", enchantDef.Id, enchantDef.RoleMask, enchantDef.ClassMask, enchantDef.SubClassMask);
        } while (qResult->NextRow());
    }
    catch (std::exception ex)
    {
        LOG_INFO("module", "Failed to load enchant table with message: {}", ex.what());
        LOG_INFO("module", "Disabling StatBooster module.");
        sBoostConfigMgr->Enable = false;
        return false;
    }

    LOG_INFO("module", ">> Done loading enchants.");
    return true;
}

void StatBoosterConfig::EnchantPool::Clear()
{
    pool.clear();
}
