#ifndef MODULE_STAT_BOOST_MGR
#define MODULE_STAT_BOOST_MGR

#include "Player.h"
#include "Chat.h"

#include "StatBoostCommon.h"

#include <random>
#include <algorithm>

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

    uint32 GetMaskFromEnum(uint32 enumValue);
    StatType GetStatTypeFromSubClass(Item* item);
    bool EnchantItem(Player* player, Item* item, EnchantmentSlot slot, uint32 enchantId, bool overwrite = false);
    StatType ScoreItem(Item* item, bool hasAdditionalSpells = false);
    StatType AnalyzeItem(Item* item);
    bool IsEquipment(Item* item);
};

#endif
