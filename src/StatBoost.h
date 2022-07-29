#ifndef MODULE_STAT_BOOST
#define MODULE_STAT_BOOST

#include "ScriptMgr.h"
#include "Chat.h"
#include "Group.h"
#include "Spell.h"
#include "Player.h"

#include "StatBoostCommon.h"

using namespace Acore::ChatCommands;

class StatBoosterPlayer : public PlayerScript
{
public:
    StatBoosterPlayer() : PlayerScript("StatBoosterPlayer") { }

    void OnLogin(Player* player) override;
    void OnLootItem(Player* player, Item* item, uint32 /*count*/, ObjectGuid /*lootguid*/) override;
    void OnQuestRewardItem(Player* player, Item* item, uint32 /*count*/) override;
    void OnCreateItem(Player* player, Item* item, uint32 /*count*/) override;
    void OnGroupRollRewardItem(Player* player, Item* item, uint32 /*count*/, RollVote /*voteType*/, Roll* /*roll*/) override;

private:
    StatBoostMgr statBoostMgr;
};

class StatBoosterWorld : public WorldScript
{
public:
    StatBoosterWorld() : WorldScript("StatBoosterWorld") { }

    void OnAfterConfigLoad(bool reload) override;
};

class StatBoosterCommands : public CommandScript
{
public:
    StatBoosterCommands() : CommandScript("StatBoosterCommands") { }

    ChatCommandTable GetCommands() const override;
    static bool HandleSBReloadCommand(ChatHandler* handler);
    static bool HandleSBAddItemCommand(ChatHandler* handler, uint32 itemId, uint32 count);
};

#endif
