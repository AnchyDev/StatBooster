#ifndef MODULE_STAT_BOOST_CFG_MGR
#define MODULE_STAT_BOOST_CFG_MGR

#include "Config.h"
#include "Random.h"
#include "Log.h"
#include "DatabaseEnv.h"
#include "StatBoostCommon.h"

#include <vector>
#include <random>
#include <algorithm>

struct EnchantDefinition
{
    uint32 Id;
    uint32 ILvlMin;
    uint32 ILvlMax;
    uint32 RoleMask;
    uint32 ClassMask;
    uint32 SubClassMask;
};

class StatBoosterConfig
{
public:
    bool Enable;
    bool VerboseEnable;

    bool OnLoginEnable;
    std::string OnLoginMessage;

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

    bool OverwriteEnchantEnable;

    class EnchantPool
    {
    public:
        void Add(EnchantDefinition definition);
        EnchantDefinition* Get(uint32 roleMask, uint32 classMask, uint32 subClassMask, uint32 itemLevel);
        bool Load();
        void Clear();

    private:
        std::vector<EnchantDefinition> pool;
        std::default_random_engine randomEngine;
    };

    EnchantPool EnchantPool;

    static StatBoosterConfig* GetInstance();

private:
    inline static StatBoosterConfig* instance;
};

#define sBoostConfigMgr StatBoosterConfig::GetInstance()

#endif
