#ifndef MODULE_STAT_BOOSTER
#define MODULE_STAT_BOOSTER

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

struct StatBoosterConfig
{
	bool OnLoginEnable;
    bool OnLootItemEnable;
    bool OnQuestRewardItemEnable;
    bool OnCraftItemEnable;

    uint32 MinQuality;
    uint32 MaxQuality;
} BoosterConfig;

#endif
