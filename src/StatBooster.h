#ifndef MODULE_STAT_BOOSTER
#define MODULE_STAT_BOOSTER

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "StatBoostMgr.h"

struct StatBoosterConfig
{
	bool OnLoginEnable;
    bool OnLootItemEnable;
    bool OnQuestRewardItemEnable;
    bool OnCraftItemEnable;

    uint32 MinQuality;
    uint32 MaxQuality;
} BoosterConfig;

class StatBoosterPlayer : public PlayerScript
{
public:
    StatBoosterPlayer() : PlayerScript("StatBoosterPlayer") { }

    void OnLogin(Player* player) override;
    void OnLootItem(Player* player, Item* item, uint32 /*count*/, ObjectGuid /*lootguid*/) override;
    void OnQuestRewardItem(Player* player, Item* item, uint32 /*count*/) override;
    void OnCreateItem(Player* player, Item* item, uint32 /*count*/) override;
    void OnRollRewardItem(Player* player, Item* item, uint32 /*count*/) override;

private:
    StatBoostMgr statBoostMgr;
};

#endif
