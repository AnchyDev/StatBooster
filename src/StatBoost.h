#ifndef MODULE_STAT_BOOST
#define MODULE_STAT_BOOST

#include "StatBoostMgr.h"
#include "ScriptMgr.h"
#include "Chat.h"

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

class StatBoosterWorld : public WorldScript
{
public:
    StatBoosterWorld() : WorldScript("StatBoosterWorld") { }

    void OnAfterConfigLoad(bool reload) override;
    void LoadEnchantTables();
};

#endif
