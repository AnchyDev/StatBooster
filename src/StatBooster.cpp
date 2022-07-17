#include "StatBooster.h"

class StatBoosterPlayer : public PlayerScript
{
public:
    StatBoosterPlayer() : PlayerScript("StatBoosterPlayer") { }

    void OnLogin(Player* player) override
    {
		if(BoosterConfig.OnLoginEnable)
		{
			ChatHandler(player->GetSession()).SendSysMessage("This server is running the StatBooster module.");
		}
	}

    void OnLootItem(Player* player, Item* item, uint32 /*count*/, ObjectGuid /*lootguid*/) override
    {
        if (BoosterConfig.OnLootItemEnable)
        {

        }
    }

    void OnQuestRewardItem(Player* player, Item* item, uint32 /*count*/) override
    {
        if (BoosterConfig.OnQuestRewardItemEnable)
        {

        }
    }

    void OnCreateItem(Player* player, Item* item, uint32 /*count*/) override
    {
        if (BoosterConfig.OnCraftItemEnable)
        {

        }
    }
};

void AddSCStatBoosterScripts()
{
	if (!sConfigMgr->GetOption<bool>("StatBooster.Enable", false))
    {
        return;
    }
	
	BoosterConfig.OnLoginEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLoginEnable", true);
    BoosterConfig.OnLootItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLootItemEnable", true);
    BoosterConfig.OnQuestRewardItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnQuestRewardItemEnable", true);
    BoosterConfig.OnCraftItemEnable = sConfigMgr->GetOption<bool>("StatBooster.OnCraftItemEnable", true);

    BoosterConfig.MinQuality = sConfigMgr->GetOption<bool>("StatBooster.MinQuality", ITEM_QUALITY_UNCOMMON);
    BoosterConfig.MaxQuality = sConfigMgr->GetOption<bool>("StatBooster.MaxQuality", ITEM_QUALITY_EPIC);
	
    new StatBoosterPlayer();
}
