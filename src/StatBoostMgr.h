#ifndef MODULE_STAT_BOOST_MGR
#define MODULE_STAT_BOOST_MGR

#include "StatBoostCfgMgr.h"
#include "Player.h"
#include "Chat.h"

#include <random>
#include <algorithm>

enum StatType
{
    STAT_TYPE_NONE = 0,
    STAT_TYPE_TANK = 1,
    STAT_TYPE_PHYS = 2,
    STAT_TYPE_HYBRID = 4,
    STAT_TYPE_SPELL = 8
};

class StatBoostMgr
{
public:
    bool BoostItem(Player* player, Item* item, uint32 chance);

private:
    struct ScoreData
    {
        StatType StatType;
        uint32 Score;
    };

    uint32 FetchEnchant(std::vector<EnchantDefinition>* pool, uint32 iLvl);
    StatType GetStatTypeFromSubClass(Item* item);
    bool EnchantItem(Player* player, Item* item, EnchantmentSlot slot, uint32 enchantId, bool overwrite = false);
    StatType ScoreItem(Item* item, bool hasAdditionalSpells = false);
    StatType AnalyzeItem(Item* item);
    bool IsEquipment(Item* item);
};

#endif
