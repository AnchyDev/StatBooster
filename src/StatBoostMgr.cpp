#include "StatBoostMgr.h"

bool StatBoostMgr::BoostItem(Player* player, Item* item)
{
    return true;
}

void StatBoostMgr::EnchantItem(Player* player, Item* item, EnchantmentSlot slot, uint32 enchantId)
{
    player->ApplyEnchantment(item, false);
    item->SetEnchantment(EnchantmentSlot(slot), enchantId, 0, 0);
    player->ApplyEnchantment(item, true);
}
