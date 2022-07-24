#include "StatBoost.h"

void PlaySoundForPlayer(Player* player, uint32 soundId)
{
    uint32 enhanceSound = soundId;
    WorldPacket soundPacket(SMSG_PLAY_SOUND, 4);
    soundPacket << enhanceSound;
    player->GetSession()->SendPacket(&soundPacket);
}

void StatBoosterPlayer::OnLogin(Player* player)
{
    if (!sBoostConfigMgr->Enable)
    {
        return;
    }

	if(sBoostConfigMgr->OnLoginEnable)
	{
		ChatHandler(player->GetSession()).SendSysMessage("This server is running the StatBooster module.");
	}
}

void StatBoosterPlayer::OnLootItem(Player* player, Item* item, uint32 /*count*/, ObjectGuid /*lootguid*/)
{
    if (!sBoostConfigMgr->Enable)
    {
        return;
    }

    if (sBoostConfigMgr->OnLootItemEnable)
    {
        ChatHandler(player->GetSession()).SendSysMessage("OnLootItem::BoostItem");
        bool result = statBoostMgr.BoostItem(player, item);

        if (result)
        {
            ChatHandler(player->GetSession()).SendSysMessage("Looted Boosted Item");
        }
    }
}

void StatBoosterPlayer::OnQuestRewardItem(Player* player, Item* item, uint32 /*count*/)
{
    if (!sBoostConfigMgr->Enable)
    {
        return;
    }

    if (sBoostConfigMgr->OnQuestRewardItemEnable)
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
    if (!sBoostConfigMgr->Enable)
    {
        return;
    }

    if (sBoostConfigMgr->OnCraftItemEnable)
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
    if (!sBoostConfigMgr->Enable)
    {
        return;
    }

    if (sBoostConfigMgr->OnLootItemEnable)
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
    sBoostConfigMgr->Enable = sConfigMgr->GetOption<bool>("StatBooster.Enable", false);

    sBoostConfigMgr->OnLoginEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLoginEnable", true);
    sBoostConfigMgr->OnLootItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLootItemEnable", true);
    sBoostConfigMgr->OnQuestRewardItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnQuestRewardItemEnable", true);
    sBoostConfigMgr->OnCraftItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnCraftItemEnable", true);

    sBoostConfigMgr->MinQuality = sConfigMgr->GetOption<uint32>("StatBooster.MinQuality", ITEM_QUALITY_UNCOMMON);
    sBoostConfigMgr->MaxQuality = sConfigMgr->GetOption<uint32>("StatBooster.MaxQuality", ITEM_QUALITY_EPIC);

    LoadEnchantTables();
}

void StatBoosterWorld::LoadEnchantTables()
{
    QueryResult qResult = WorldDatabase.Query("SELECT Id, iLvlMin, iLvlMax, RoleMask FROM statbooster_enchant_template");

    if (!qResult)
    {
        LOG_INFO("module", "Failed to load StatBooster enchant definitions from 'statbooster_enchant_template' table.");
        return;
    }

    LOG_INFO("module", "Loading StatBooster enchants from 'statbooster_enchant_template' table.");

    do
    {
        Field* fields = qResult->Fetch();

        EnchantDefinition enchantDef;

        enchantDef.Id = fields[0].Get<uint32>();
        enchantDef.ILvlMin = fields[1].Get<uint32>();
        enchantDef.ILvlMax = fields[2].Get<uint32>();
        uint32 roleMask = fields[3].Get<uint32>();


        if ((roleMask & STAT_TYPE_TANK) == STAT_TYPE_TANK)
        {
            sBoostConfigMgr->TankEnchantPool.push_back(enchantDef);
            LOG_INFO("module", "Loading Enchant ID {} with mask {} into TANK", enchantDef.Id, roleMask);
        }
        if ((roleMask & STAT_TYPE_PHYS) == STAT_TYPE_PHYS)
        {
            sBoostConfigMgr->PhysEnchantPool.push_back(enchantDef);
            LOG_INFO("module", "Loading Enchant ID {} with mask {} into PHYS", enchantDef.Id, roleMask);
        }
        if ((roleMask & STAT_TYPE_HYBRID) == STAT_TYPE_HYBRID)
        {
            sBoostConfigMgr->HybridEnchantPool.push_back(enchantDef);
            LOG_INFO("module", "Loading Enchant ID {} with mask {} into HYBRID", enchantDef.Id, roleMask);
        }
        if ((roleMask & STAT_TYPE_SPELL) == STAT_TYPE_SPELL)
        {
            sBoostConfigMgr->SpellEnchantPool.push_back(enchantDef);
            LOG_INFO("module", "Loading Enchant ID {} with mask {} into SPELL", enchantDef.Id, roleMask);
        }
        if (roleMask == STAT_TYPE_NONE)
        {
            sBoostConfigMgr->TankEnchantPool.push_back(enchantDef);
            sBoostConfigMgr->PhysEnchantPool.push_back(enchantDef);
            sBoostConfigMgr->HybridEnchantPool.push_back(enchantDef);
            sBoostConfigMgr->SpellEnchantPool.push_back(enchantDef);
            LOG_INFO("module", "Loading Enchant ID {} with mask {} into ALL", enchantDef.Id, roleMask);
        }
    } while (qResult->NextRow());

    LOG_INFO("module", ">> Done loading enchants.");
}

void AddSCStatBoosterScripts()
{
    new StatBoosterWorld();
    new StatBoosterPlayer();
}
