#include "StatBooster.h"


void PlaySoundForPlayer(Player* player, uint32 soundId)
{
    uint32 enhanceSound = soundId;
    WorldPacket soundPacket(SMSG_PLAY_SOUND, 4);
    soundPacket << enhanceSound;
    player->GetSession()->SendPacket(&soundPacket);
}

void StatBoosterPlayer::OnLogin(Player* player)
{
    if (!BoosterConfig.Enable)
    {
        return;
    }

	if(BoosterConfig.OnLoginEnable)
	{
		ChatHandler(player->GetSession()).SendSysMessage("This server is running the StatBooster module.");
	}
}

void StatBoosterPlayer::OnLootItem(Player* player, Item* item, uint32 /*count*/, ObjectGuid /*lootguid*/)
{
    if (!BoosterConfig.Enable)
    {
        return;
    }

    if (BoosterConfig.OnLootItemEnable)
    {
        bool result = statBoostMgr.BoostItem(player, item);

        if (result)
        {
            ChatHandler(player->GetSession()).SendSysMessage("Looted Boosted Item");
        }
    }
}

void StatBoosterPlayer::OnQuestRewardItem(Player* player, Item* item, uint32 /*count*/)
{
    if (!BoosterConfig.Enable)
    {
        return;
    }

    if (BoosterConfig.OnQuestRewardItemEnable)
    {
        bool result = statBoostMgr.BoostItem(player, item);

        if (result)
        {
            ChatHandler(player->GetSession()).SendSysMessage("Looted Boosted Item");
        }
    }
}

void StatBoosterPlayer::OnCreateItem(Player* player, Item* item, uint32 /*count*/)
{
    if (!BoosterConfig.Enable)
    {
        return;
    }

    if (BoosterConfig.OnCraftItemEnable)
    {
        bool result = statBoostMgr.BoostItem(player, item);

        if (result)
        {
            ChatHandler(player->GetSession()).SendSysMessage("Looted Boosted Item");
        }
    }
}

void StatBoosterPlayer::OnRollRewardItem(Player* player, Item* item, uint32 /*count*/)
{
    if (!BoosterConfig.Enable)
    {
        return;
    }

    if (BoosterConfig.OnLootItemEnable)
    {
        bool result = statBoostMgr.BoostItem(player, item);

        if (result)
        {
            ChatHandler(player->GetSession()).SendSysMessage("Looted Boosted Item");
        }
    }
}

void StatBoosterWorld::OnAfterConfigLoad(bool reload)
{
    BoosterConfig.Enable = sConfigMgr->GetOption<bool>("StatBooster.Enable", false);

    BoosterConfig.OnLoginEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLoginEnable", true);
    BoosterConfig.OnLootItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLootItemEnable", true);
    BoosterConfig.OnQuestRewardItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnQuestRewardItemEnable", true);
    BoosterConfig.OnCraftItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnCraftItemEnable", true);

    BoosterConfig.MinQuality = sConfigMgr->GetOption<uint32>("StatBooster.MinQuality", ITEM_QUALITY_UNCOMMON);
    BoosterConfig.MaxQuality = sConfigMgr->GetOption<uint32>("StatBooster.MaxQuality", ITEM_QUALITY_EPIC);

    LoadEnchantTables();
}

void StatBoosterWorld::LoadEnchantTables()
{
    //TODO: LOAD IN ENCHANT DEFINITIONS FROM DB
}

void AddSCStatBoosterScripts()
{
    new StatBoosterPlayer();
}
