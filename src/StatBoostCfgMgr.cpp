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

EnchantDefinition* StatBoosterConfig::EnchantPool::Get(uint32 roleMask, uint32 classMask, uint32 itemLevel)
{
    std::shuffle(std::begin(pool), std::end(pool), randomEngine);

    if (roleMask == 0 && classMask == 0)
    {
        uint32 randItem = urand(0, (sizeof(pool) / sizeof(pool[0])));
        return &pool[randItem];
    }

    auto iterator = std::find_if(pool.begin(), pool.end(), [&](const EnchantDefinition& data)
    {
            return (data.RoleMask == roleMask || data.RoleMask == 0) &&
                (data.ClassMask == classMask || data.ClassMask == 0) &&
                (itemLevel >= data.ILvlMin && itemLevel <= data.ILvlMax);
    });

    if (!(iterator == pool.end()))
    {
        return &(*iterator);
    }

    return 0;
}
