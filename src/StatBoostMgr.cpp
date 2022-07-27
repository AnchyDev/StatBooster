#include "StatBoostMgr.h"

uint32 GetMaskFromClass(uint32 itemClass)
{
    switch (itemClass)
    {
    case ITEM_CLASS_WEAPON:
        return 1;

    case ITEM_CLASS_ARMOR:
        return 2;
    }

    return 0;
}

uint32 GetMaskFromSubClass(uint32 itemClass, uint32 itemSubClass)
{
    switch (itemClass)
    {
    case ITEM_CLASS_WEAPON:
        switch (itemSubClass)
        {
        case ITEM_SUBCLASS_WEAPON_AXE:
            return 1;
        case ITEM_SUBCLASS_WEAPON_AXE2:
            return 2;
        case ITEM_SUBCLASS_WEAPON_BOW:
            return 4;
        case ITEM_SUBCLASS_WEAPON_GUN:
            return 8;
        case ITEM_SUBCLASS_WEAPON_MACE:
            return 16;
        case ITEM_SUBCLASS_WEAPON_MACE2:
            return 32;
        case ITEM_SUBCLASS_WEAPON_POLEARM:
            return 64;
        case ITEM_SUBCLASS_WEAPON_SWORD:
            return 128;
        case ITEM_SUBCLASS_WEAPON_SWORD2:
            return 256;
        case ITEM_SUBCLASS_WEAPON_STAFF:
            return 512;
        case ITEM_SUBCLASS_WEAPON_EXOTIC:
            return 1024;
        case ITEM_SUBCLASS_WEAPON_EXOTIC2:
            return 2048;
        case ITEM_SUBCLASS_WEAPON_FIST:
            return 4096;
        case ITEM_SUBCLASS_WEAPON_MISC:
            return 8192;
        case ITEM_SUBCLASS_WEAPON_DAGGER:
            return 16384;
        case ITEM_SUBCLASS_WEAPON_THROWN:
            return 32768;
        case ITEM_SUBCLASS_WEAPON_SPEAR:
            return 65536;
        case ITEM_SUBCLASS_WEAPON_CROSSBOW:
            return 131072;
        case ITEM_SUBCLASS_WEAPON_WAND:
            return 262144;
        case ITEM_SUBCLASS_WEAPON_FISHING_POLE:
            return 524288;
        }
        break;

    case ITEM_CLASS_ARMOR:
        switch (itemSubClass)
        {
        case ITEM_SUBCLASS_ARMOR_MISC:
            return 1;
        case ITEM_SUBCLASS_ARMOR_CLOTH:
            return 2;
        case ITEM_SUBCLASS_ARMOR_LEATHER:
            return 4;
        case ITEM_SUBCLASS_ARMOR_MAIL:
            return 8;
        case ITEM_SUBCLASS_ARMOR_PLATE:
            return 16;
        case ITEM_SUBCLASS_ARMOR_BUCKLER:
            return 32;
        case ITEM_SUBCLASS_ARMOR_SHIELD:
            return 64;
        case ITEM_SUBCLASS_ARMOR_LIBRAM:
            return 128;
        case ITEM_SUBCLASS_ARMOR_IDOL:
            return 256;
        case ITEM_SUBCLASS_ARMOR_TOTEM:
            return 512;
        case ITEM_SUBCLASS_ARMOR_SIGIL:
            return 1024;
        }
    }

    return 0;
}

StatType StatBoostMgr::GetStatTypeFromSubClass(Item* item)
{
    if (item->GetTemplate()->Class == ITEM_CLASS_WEAPON)
    {
        switch (item->GetTemplate()->SubClass)
        {
        case ITEM_SUBCLASS_WEAPON_MACE2:
        case ITEM_SUBCLASS_WEAPON_POLEARM:
        case ITEM_SUBCLASS_WEAPON_SPEAR:
        case ITEM_SUBCLASS_WEAPON_GUN:
        case ITEM_SUBCLASS_WEAPON_BOW:
        case ITEM_SUBCLASS_WEAPON_CROSSBOW:
            switch (urand(0, 2))
            {
            case 0:
                return STAT_TYPE_TANK;

            case 1:
                return STAT_TYPE_PHYS;

            case 2:
                return STAT_TYPE_HYBRID;
            }

        case ITEM_SUBCLASS_WEAPON_THROWN:
            return STAT_TYPE_PHYS;

        case ITEM_SUBCLASS_WEAPON_DAGGER:
            switch (urand(0, 2))
            {
            case 0:
                return STAT_TYPE_PHYS;

            case 1:
                return STAT_TYPE_HYBRID;

            case 2:
                return STAT_TYPE_SPELL;
            }

        case ITEM_SUBCLASS_WEAPON_STAFF:
            switch (urand(0, 3))
            {
            case 0:
                return STAT_TYPE_TANK;

            case 1:
                return STAT_TYPE_PHYS;

            case 2:
                return STAT_TYPE_HYBRID;

            case 3:
                return STAT_TYPE_SPELL;
            }

        case ITEM_SUBCLASS_WEAPON_AXE:
        case ITEM_SUBCLASS_WEAPON_AXE2:
        case ITEM_SUBCLASS_WEAPON_MACE:
        case ITEM_SUBCLASS_WEAPON_SWORD:
        case ITEM_SUBCLASS_WEAPON_SWORD2:
        case ITEM_SUBCLASS_WEAPON_FIST:
            switch (urand(0, 1))
            {
            case 0:
                return STAT_TYPE_TANK;

            case 1:
                return STAT_TYPE_PHYS;
            }

        case ITEM_SUBCLASS_WEAPON_WAND:
            return STAT_TYPE_SPELL;
        }
    }
    else if (item->GetTemplate()->Class == ITEM_CLASS_ARMOR)
    {
        switch (item->GetTemplate()->SubClass)
        {
        case ITEM_SUBCLASS_ARMOR_CLOTH:
            switch (item->GetTemplate()->InventoryType)
            {
            case INVTYPE_CLOAK:
                switch (urand(0, 3))
                {
                case 0:
                    return STAT_TYPE_TANK;

                case 1:
                    return STAT_TYPE_PHYS;

                case 2:
                    return STAT_TYPE_HYBRID;

                case 3:
                    return STAT_TYPE_SPELL;
                }

            default:
                return STAT_TYPE_SPELL;
            }
            break;

        case ITEM_SUBCLASS_ARMOR_LEATHER:
        case ITEM_SUBCLASS_ARMOR_MAIL:
        case ITEM_SUBCLASS_ARMOR_PLATE:
            switch (urand(0, 3))
            {
            case 0:
                return STAT_TYPE_TANK;

            case 1:
                return STAT_TYPE_PHYS;

            case 2:
                return STAT_TYPE_HYBRID;

            case 3:
                return STAT_TYPE_SPELL;
            }

        case ITEM_SUBCLASS_ARMOR_BUCKLER:
        case ITEM_SUBCLASS_ARMOR_SHIELD:
            switch (urand(0, 1))
            {
            case 0:
                return STAT_TYPE_TANK;
            case 1:
                return STAT_TYPE_SPELL;
            }
        }
    }

    return STAT_TYPE_NONE;
}   

StatType StatBoostMgr::ScoreItem(Item* item, bool hasAdditionalSpells)
{
    ScoreData tankScore { STAT_TYPE_TANK, 0 },
        physScore { STAT_TYPE_PHYS, 0 },
        hybridScore { STAT_TYPE_HYBRID, 0 },
        spellScore { STAT_TYPE_SPELL, 0 };

    //Store the scores in a vector so I can order by highest for a winner.
    std::vector<ScoreData*> scores;
    scores.push_back(&tankScore);
    scores.push_back(&physScore);
    scores.push_back(&hybridScore);
    scores.push_back(&spellScore);

    //TODO: IMPLEMENT SCORING
    auto itemTemplate = item->GetTemplate();
    auto subClass = itemTemplate->SubClass;

    for (uint32 i = 0; i < itemTemplate->StatsCount; i++)
    {
        auto stat = itemTemplate->ItemStat[i];
        uint32 statType = stat.ItemStatType;

        switch (statType)
        {
        case ITEM_MOD_ARMOR_PENETRATION_RATING:
        case ITEM_MOD_ATTACK_POWER:
        case ITEM_MOD_STRENGTH:
        case ITEM_MOD_AGILITY:
            tankScore.Score += 1;
            physScore.Score += 2;
            hybridScore.Score += 1;
            break;

        case ITEM_MOD_INTELLECT:
            switch (subClass)
            {
            case ITEM_SUBCLASS_ARMOR_CLOTH:
                spellScore.Score += 1;
                break;

            case ITEM_SUBCLASS_ARMOR_LEATHER:
                hybridScore.Score += 1;
                spellScore.Score += 1;
                break;

            case ITEM_SUBCLASS_ARMOR_MAIL:
                tankScore.Score += 1;
                hybridScore.Score += 1;
                spellScore.Score += 1;
                break;

            case ITEM_SUBCLASS_ARMOR_PLATE:
                tankScore.Score += 1;
                spellScore.Score += 1;
                break;

            default:
                tankScore.Score += 1;
                hybridScore.Score += 2;
                spellScore.Score += 3;
                break;
            }
            break;

        case ITEM_MOD_SPIRIT:
        case ITEM_MOD_MANA_REGENERATION:
        case ITEM_MOD_SPELL_HEALING_DONE:
        case ITEM_MOD_SPELL_POWER:
        case ITEM_MOD_SPELL_PENETRATION:
        case ITEM_MOD_SPELL_DAMAGE_DONE:
            spellScore.Score += 1;
            break;

        case ITEM_MOD_BLOCK_RATING:
        case ITEM_MOD_PARRY_RATING:
        case ITEM_MOD_DODGE_RATING:
        case ITEM_MOD_DEFENSE_SKILL_RATING:
            tankScore.Score += 3;
            break;
        }
    }

    //Sometimes stats are stored as additional spell effects and also need to be checked.
    if (hasAdditionalSpells)
    {
        for (auto spell : itemTemplate->Spells)
        {
            if (spell.SpellId)
            {
                auto spellInfo = sSpellMgr->GetSpellInfo(spell.SpellId);

                if (spellInfo->HasAura(SPELL_AURA_MOD_ATTACK_POWER))
                {
                    tankScore.Score += 1;
                    physScore.Score += 2;
                    hybridScore.Score += 1;
                }

                if (spellInfo->HasAura(SPELL_AURA_MOD_HEALING_DONE) ||
                    spellInfo->HasAura(SPELL_AURA_MOD_POWER_REGEN) ||
                    spellInfo->HasAura(SPELL_AURA_MOD_DAMAGE_DONE))
                {
                    spellScore.Score += 1;
                }
            }
        }
    }

    //Tally up the results, the highest score is picked.
    auto winningScore = *scores[0];
    for (auto score : scores)
    {
        if (score->Score > winningScore.Score)
        {
            winningScore = *score;
        }
    }

    //No stats on the items could be scored.
    if (winningScore.Score < 1)
    {
        return STAT_TYPE_NONE;
    }

    return winningScore.StatType;
}

StatType StatBoostMgr::AnalyzeItem(Item* item)
{
    auto itemTemplate = item->GetTemplate();

    //The spellids need to be checked because the Spells array is always allocated to a fixed size.
    //Thus we need to count how many VALID spells are in the array.
    uint32 spellsCount = 0;
    for (auto spell : itemTemplate->Spells)
    {
        if (spell.SpellId)
        {
            spellsCount++;
        }
    }

    if (itemTemplate->StatsCount < 1 && spellsCount < 1)
    {
        return GetStatTypeFromSubClass(item);
    }

    return ScoreItem(item, spellsCount);
}

bool StatBoostMgr::BoostItem(Player* player, Item* item, uint32 chance)
{
    //Is not weapon or armor.
    if (!IsEquipment(item))
    {
        return false;
    }

    if (item->GetTemplate()->Quality < sBoostConfigMgr->MinQuality ||
        item->GetTemplate()->Quality > sBoostConfigMgr->MaxQuality)
    {
        return false;
    }

    //Roll for the chance to upgrade.
    uint32 roll = urand(0, 100);

    if (roll > chance)
    {
        return false;
    }

    //Fetch the type of stats that should be applied to the piece.
    StatType statType = AnalyzeItem(item);

    //Failed to find a stat type.
    if (statType == STAT_TYPE_NONE)
    {
        statType = GetStatTypeFromSubClass(item);
    }

    uint32 itemClass = item->GetTemplate()->Class;
    uint32 itemSubClass = item->GetTemplate()->SubClass;
    uint32 itemLevel = item->GetTemplate()->ItemLevel;

    uint32 itemClassMask = GetMaskFromClass(itemClass);

    if (!itemClassMask)
    {
        return false;
    }

    uint32 itemSubClassMask = GetMaskFromSubClass(itemClass, itemSubClass);

    if (!itemSubClassMask)
    {
        return false;
    }

    //Fetch an enchant from the enchant pool.
    auto enchant = sBoostConfigMgr->EnchantPool.Get(statType, itemClassMask, itemSubClassMask, itemLevel);

    //Failed to find a valid enchant.
    if (!enchant)
    {
        return false;
    }

    return EnchantItem(player, item, BONUS_ENCHANTMENT_SLOT, enchant->Id, sBoostConfigMgr->OverwriteEnchantEnable);
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
