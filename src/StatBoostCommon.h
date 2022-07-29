
#ifndef MODULE_STAT_BOOST_COMMON
#define MODULE_STAT_BOOST_COMMON

#include <format>

#include "Chat.h"
#include "Define.h"
#include "Player.h"
#include "ScriptMgr.h"

#include "StatBoostCfgMgr.h"
/*
#include <chrono>
#include <vector>
#include <format>
#include <random>
#include <algorithm>

#include "Define.h"
#include "Config.h"
#include "Log.h"
#include "Random.h"
#include "Player.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "ScriptMgr.h"

#include "StatBoostCfgMgr.h"
#include "StatBoostMgr.h"*/

class StatBoostCommon
{
public:
    template<typename T>
    static uint32 MeasureExecution(T&& func);
};

#endif
