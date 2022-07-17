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
};

void AddSCStatBoosterScripts()
{
	if (!sConfigMgr->GetOption<bool>("StatBooster.Enable", false))
    {
        return;
    }
	
	BoosterConfig.OnLoginEnable = sConfigMgr->GetOption<bool>("StatBooster.OnLoginEnable", true);
	
    new StatBoosterPlayer();
}
