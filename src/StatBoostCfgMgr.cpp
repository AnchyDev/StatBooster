#include "StatBoostCfgMgr.h"
#include "Log.h"

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
