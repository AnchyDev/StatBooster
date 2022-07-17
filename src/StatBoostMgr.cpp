#include "StatBoostMgr.h"

StatType StatBoostMgr::AnalyzeItem(Item* item)
{
    return STAT_TYPE_NONE;
}

bool StatBoostMgr::BoostItem(Player* player, Item* item)
{
    if (!IsEquipment(item))
    {
        return false;
    }

    StatType statType = AnalyzeItem(item);

    return true;
}

bool StatBoostMgr::IsEquipment(Item* item)
{
    auto itemTemplate = item->GetTemplate();

    if (itemTemplate->Class != ITEM_CLASS_WEAPON &&
        itemTemplate->Class != ITEM_CLASS_ARMOR)
    {
        return false;
    }

    return true;
}

bool StatBoostMgr::EnchantItem(Player* player, Item* item, EnchantmentSlot slot, uint32 enchantId, bool overwrite)
{
    if (item->GetEnchantmentId(slot) && !overwrite)
    {
        return false;
    }

    player->ApplyEnchantment(item, false);
    item->SetEnchantment(EnchantmentSlot(slot), enchantId, 0, 0);
    player->ApplyEnchantment(item, true);

    return true;
}
