#ifndef MODULE_STAT_BOOST_CFG_MGR
#define MODULE_STAT_BOOST_CFG_MGR

#include <random>
#include <algorithm>

#include "StatBoostCommon.h"

struct EnchantDefinition
{
    uint32 Id;
    uint32 ILvlMin;
    uint32 ILvlMax;
    uint32 RoleMask;
    uint32 ClassMask;
    uint32 SubClassMask;
    uint32 ItemTypeMask;
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

    bool SoulbindOnEnchantRoll;
    bool SoulbindOnEnchantCraft;
    bool SoulbindOnEnchantLoot;
    bool SoulbindOnEnchantQuest;

    bool AnnounceBoostEnable;
    std::string AnnounceLoot;
    std::string AnnounceCraft;
    std::string AnnounceQuest;

    bool OverwriteEnchantEnable;

    class EnchantPool
    {
    public:
        void Add(EnchantDefinition definition);
        EnchantDefinition* Get(uint32 roleMask, uint32 classMask, uint32 subClassMask, uint32 itemTypeMask, uint32 itemLevel);
        bool Load();
        void Clear();

    private:
        std::vector<EnchantDefinition> pool;
        std::default_random_engine randomEngine;
    };

    EnchantPool EnchantPool;

    struct EnchantScore
    {
        uint32 modType;
        uint32 modId;
        uint32 subclass;

        uint32 tankScore;
        uint32 physScore;
        uint32 spellScore;
        uint32 hybridScore;
    };

    class EnchantScorePool
    {
    public:
        std::vector<EnchantScore>* Get();
        void Add(EnchantScore score);
        bool Load();
        void Clear();
        void Evaluate(uint32 modType, uint32 modId, uint32 subclass, uint32& tankScore, uint32& physScore, uint32& spellScore, uint32& hybridScore);

    private:
        std::vector<EnchantScore> scores;
    };

    EnchantScorePool EnchantScores;

    static StatBoosterConfig* GetInstance();

private:
    inline static StatBoosterConfig* instance;
};

#define sBoostConfigMgr StatBoosterConfig::GetInstance()

#endif
