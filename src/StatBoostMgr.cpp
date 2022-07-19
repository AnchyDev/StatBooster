#include "StatBoostMgr.h"

StatType StatBoostMgr::AnalyzeItem(Item* item)
{
    auto iTemplate = item->GetTemplate();

    uint32 spellsCount = 0;
    for (int i = 0; i < (sizeof(iTemplate->Spells) / sizeof(iTemplate->Spells[0]); i++)
    {
        if (iTemplate->Spells[i].SpellId)
        {
            spellsCount++;
        }
    }

    if (iTemplate->StatsCount < 1 && spellsCount < 1)
    {
        return STAT_TYPE_NONE;
    }

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
