#ifndef MODULE_STAT_BOOST_CFG_MGR
#define MODULE_STAT_BOOST_CFG_MGR

#include "Config.h"
#include <vector>

struct EnchantDefinition
{
    uint32 Id;
    uint32 ILvlMin;
    uint32 ILvlMax;
};

class StatBoosterConfig
{
public:
    bool Enable;

    bool OnLoginEnable;
    bool OnLootItemEnable;
    bool OnQuestRewardItemEnable;
    bool OnCraftItemEnable;

    uint32 LootItemChance;
    uint32 QuestRewardChance;
    uint32 CraftItemChance;

    uint32 MinQuality;
    uint32 MaxQuality;

    bool PlaySoundEnable;
    uint32 SoundId;

    bool AnnounceBoostEnable;
    std::string AnnounceLoot;
    std::string AnnounceCraft;
    std::string AnnounceQuest;

    std::vector<EnchantDefinition> TankEnchantPool;
    std::vector<EnchantDefinition> PhysEnchantPool;
    std::vector<EnchantDefinition> HybridEnchantPool;
    std::vector<EnchantDefinition> SpellEnchantPool;

    static StatBoosterConfig* GetInstance();

private:
    inline static StatBoosterConfig* instance;
};

#define sBoostConfigMgr StatBoosterConfig::GetInstance()

#endif
