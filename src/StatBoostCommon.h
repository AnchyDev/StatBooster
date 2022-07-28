
#ifndef MODULE_STAT_BOOST_COMMON
#define MODULE_STAT_BOOST_COMMON

#include "Define.h"

#include <chrono>

class StatBoostCommon
{
public:
    template<typename T>
    static uint32 MeasureExecution(T&& func);
};

#endif
