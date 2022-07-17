#ifndef MODULE_STAT_BOOST_MGR
#define MODULE_STAT_BOOST_MGR

#include "Player.h"

class StatBoostMgr
{
public:
    bool BoostItem(Player* player, Item* item);

private:
    bool EnchantItem(Player* player, Item* item, EnchantmentSlot slot, uint32 enchantId, bool overwrite = false);
};

#endif
