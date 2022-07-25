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
		ChatHandler(player->GetSession()).SendSysMessage(sBoostConfigMgr->OnLoginMessage);
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
        bool result = statBoostMgr.BoostItem(player, item, sBoostConfigMgr->LootItemChance);

        if (result)
        {
            if (sBoostConfigMgr->AnnounceBoostEnable)
            {
                ChatHandler(player->GetSession()).SendSysMessage(sBoostConfigMgr->AnnounceLoot);
            }

            if (sBoostConfigMgr->PlaySoundEnable)
            {
                PlaySoundForPlayer(player, sBoostConfigMgr->SoundId);
            }
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
        bool result = statBoostMgr.BoostItem(player, item, sBoostConfigMgr->QuestRewardChance);

        if (result)
        {
            if (sBoostConfigMgr->AnnounceBoostEnable)
            {
                ChatHandler(player->GetSession()).SendSysMessage(sBoostConfigMgr->AnnounceQuest);
            }

            if (sBoostConfigMgr->PlaySoundEnable)
            {
                PlaySoundForPlayer(player, sBoostConfigMgr->SoundId);
            }
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
        bool result = statBoostMgr.BoostItem(player, item, sBoostConfigMgr->CraftItemChance);

        if (result)
        {
            if (sBoostConfigMgr->AnnounceBoostEnable)
            {
                ChatHandler(player->GetSession()).SendSysMessage(sBoostConfigMgr->AnnounceCraft);
            }

            if (sBoostConfigMgr->PlaySoundEnable)
            {
                PlaySoundForPlayer(player, sBoostConfigMgr->SoundId);
            }
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
        bool result = statBoostMgr.BoostItem(player, item, sBoostConfigMgr->LootItemChance);

        if (result)
        {
            if (sBoostConfigMgr->AnnounceBoostEnable)
            {
                ChatHandler(player->GetSession()).SendSysMessage(sBoostConfigMgr->AnnounceLoot);
            }

            if (sBoostConfigMgr->PlaySoundEnable)
            {
                PlaySoundForPlayer(player, sBoostConfigMgr->SoundId);
            }
        }
    }
}

void StatBoosterWorld::OnAfterConfigLoad(bool /*reload*/)
{
    sBoostConfigMgr->Enable = sConfigMgr->GetOption<bool>("StatBooster.Enable", false);

    sBoostConfigMgr->OnLoginEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLoginEnable", true);
    sBoostConfigMgr->OnLoginMessage = sConfigMgr->GetOption<std::string>("StatBooster.OnLoginMessage", "This server is running the StatBooster module.");

    sBoostConfigMgr->OnLootItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLootItemEnable", true);
    sBoostConfigMgr->OnQuestRewardItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnQuestRewardItemEnable", true);
    sBoostConfigMgr->OnCraftItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnCraftItemEnable", true);

    sBoostConfigMgr->LootItemChance = sConfigMgr->GetOption<uint32>("StatBooster.LootItemChance", 100);
    sBoostConfigMgr->QuestRewardChance = sConfigMgr->GetOption<uint32>("StatBooster.QuestRewardChance", 100);
    sBoostConfigMgr->CraftItemChance = sConfigMgr->GetOption<uint32>("StatBooster.CraftItemChance", 100);

    sBoostConfigMgr->MinQuality = sConfigMgr->GetOption<uint32>("StatBooster.MinQuality", ITEM_QUALITY_UNCOMMON);
    sBoostConfigMgr->MaxQuality = sConfigMgr->GetOption<uint32>("StatBooster.MaxQuality", ITEM_QUALITY_EPIC);

    sBoostConfigMgr->PlaySoundEnable = sConfigMgr->GetOption<bool>("StatBooster.PlaySoundEnable", true);
    sBoostConfigMgr->SoundId = sConfigMgr->GetOption<uint32>("StatBooster.SoundId", 120);

    sBoostConfigMgr->AnnounceBoostEnable = sConfigMgr->GetOption<bool>("StatBooster.AnnounceBoostEnable", true);
    sBoostConfigMgr->AnnounceLoot = sConfigMgr->GetOption<std::string>("StatBooster.AnnounceLoot", "You looted a boosted item.");
    sBoostConfigMgr->AnnounceQuest = sConfigMgr->GetOption<std::string>("StatBooster.AnnounceQuest", "You received a boosted item.");
    sBoostConfigMgr->AnnounceCraft = sConfigMgr->GetOption<std::string>("StatBooster.AnnounceCraft", "You crafted a boosted item.");

    sBoostConfigMgr->OverwriteEnchantEnable = sConfigMgr->GetOption<bool>("StatBooster.OverwriteEnchantEnable", true);

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
