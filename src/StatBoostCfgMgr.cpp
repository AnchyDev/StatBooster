#include "StatBoostCfgMgr.h"

StatBoosterConfig* StatBoosterConfig::GetInstance()
{
    if (!instance)
    {
        instance = new StatBoosterConfig();
    }

    return instance;
}
