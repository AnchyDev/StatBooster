
#ifndef MODULE_STAT_BOOST_COMMON
#define MODULE_STAT_BOOST_COMMON

#include "Define.h"

#include "StatBoostCfgMgr.h"
#include "StatBoostMgr.h"

#include <chrono>
#include <format>

enum StatType
{
    STAT_TYPE_NONE = 0,
    STAT_TYPE_TANK = 1,
    STAT_TYPE_PHYS = 2,
    STAT_TYPE_HYBRID = 4,
    STAT_TYPE_SPELL = 8
};

class StatBoostCommon
{
public:
    template<typename T>
    static uint32 MeasureExecution(T&& func);
};

#endif
