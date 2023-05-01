DELETE FROM `command` WHERE name='sb';
INSERT INTO `command`(`name`, `security`, `help`) VALUES ('sb', 3, 'Syntax: .sb - type .sb to list subcommands.');

DELETE FROM `command` WHERE name='sb additem';
INSERT INTO `command`(`name`, `security`, `help`) VALUES ('sb additem', 3, 'Syntax: .sb additem <itemid> <count> - tries to add an enchanted item to targeted player.');

DROP TABLE IF EXISTS `statbooster_enchant_template`;
CREATE TABLE IF NOT EXISTS `statbooster_enchant_template` (
  `Id` int unsigned DEFAULT NULL,
  `iLvlMin` int unsigned DEFAULT NULL,
  `iLvlMax` int unsigned DEFAULT NULL,
  `RoleMask` int unsigned DEFAULT NULL,
  `ClassMask` int unsigned DEFAULT NULL,
  `SubClassMask` int unsigned DEFAULT NULL,
  `Description` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `Note` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `statbooster_enchant_template` (`Id`, `iLvlMin`, `iLvlMax`, `RoleMask`, `ClassMask`, `SubClassMask`, `Description`, `Note`) VALUES
	(68, 1, 20, 3, 0, 0, '+1 Strength', 'TANK/PHYS - ALL - ALL'),
	(74, 1, 20, 7, 0, 0, '+1 Agility', 'TANK/PHYS/HYBRID - ALL - ALL'),
	(79, 1, 20, 12, 0, 0, '+1 Intellect', 'HYBRID/SPELL - ALL - ALL'),
	(206, 1, 20, 8, 0, 0, '+1 Spell Power', 'SPELL - ALL - ALL'),
	(66, 1, 20, 0, 0, 0, '+1 Stamina', 'ALL - ALL - ALL'),
	(82, 1, 20, 8, 0, 0, '+1 Spirit', 'SPELL - ALL - ALL'),
	(75, 10, 30, 7, 0, 0, '+2 Agility', 'TANK/PHYS/HYBRID - ALL - ALL'),
	(69, 10, 30, 3, 0, 0, '+2 Strength', 'TANK/PHYS - ALL - ALL'),
	(80, 10, 30, 12, 0, 0, '+2 Intellect', 'HYBRID/SPELL - ALL - ALL'),
	(72, 10, 30, 0, 0, 0, '+2 Stamina', 'ALL - ALL - ALL'),
	(83, 10, 30, 8, 0, 0, '+2 Spirit', 'SPELL - ALL - ALL'),
	(207, 10, 30, 8, 0, 0, '+2 Spell Power', 'SPELL - ALL - ALL'),
	(76, 20, 40, 7, 0, 0, '+3 Agility', 'TANK/PHYS/HYBRID - ALL - ALL'),
	(81, 20, 40, 12, 0, 0, '+3 Intellect', 'HYBRID/SPELL - ALL - ALL'),
	(73, 20, 40, 0, 0, 0, '+3 Stamina', 'ALL - ALL - ALL'),
	(64, 20, 40, 8, 0, 0, '+3 Spirit', 'SPELL - ALL - ALL'),
	(70, 20, 40, 3, 0, 0, '+3 Strength', 'TANK/PHYS - ALL - ALL'),
	(2910, 20, 40, 8, 0, 0, '+3 Spell Power', 'SPELL - ALL - ALL'),
	(90, 30, 50, 7, 0, 0, '+4 Agility', 'TANK/PHYS/HYRBRID - ALL - ALL'),
	(94, 30, 50, 12, 0, 0, '+4 Intellect', 'HYBRID/SPELL - ALL - ALL'),
	(102, 30, 50, 0, 0, 0, '+4 Stamina', 'ALL - ALL - ALL'),
	(99, 30, 50, 8, 0, 0, '+4 Spirit', 'SPELL - ALL - ALL'),
	(106, 30, 50, 3, 0, 0, '+4 Strength', 'TANK/PHYS - ALL - ALL'),
	(208, 30, 50, 8, 0, 0, '+4 Spell Power', 'SPELL - ALL - ALL'),
	(91, 40, 60, 7, 0, 0, '+5 Agility', 'TANK/PHYS/HYBRID - ALL - ALL'),
	(95, 40, 60, 12, 0, 0, '+5 Intellect', 'HYBRID/SPELL - ALL - ALL'),
	(103, 40, 60, 0, 0, 0, '+5 Stamina', 'ALL - ALL - ALL'),
	(99, 40, 60, 8, 0, 0, '+5 Spirit', 'SPELL - ALL - ALL'),
	(107, 40, 60, 3, 0, 0, '+5 Strength', 'TANK/PHYS - ALL - ALL'),
	(209, 40, 60, 8, 0, 0, '+5 Spell Power', 'SPELL - ALL - ALL'),
	(92, 50, 70, 7, 0, 0, '+6 Agility', 'TANK/PHYS/HYBRID - ALL - ALL'),
	(96, 50, 70, 12, 0, 0, '+6 Intellect', 'HYBRID/SPELL - ALL - ALL'),
	(104, 50, 70, 0, 0, 0, '+6 Stamina', 'ALL - ALL - ALL'),
	(100, 50, 70, 8, 0, 0, '+6 Spirit', 'SPELL - ALL - ALL'),
	(108, 50, 70, 3, 0, 0, '+6 Strength', 'TANK/PHYS - ALL - ALL'),
	(210, 50, 70, 8, 0, 0, '+6 Spell Power', 'SPELL - ALL - ALL'),
	(93, 60, 80, 7, 0, 0, '+7 Agility', 'TANK/PHYS/HYBRID - ALL - ALL'),
	(97, 60, 80, 12, 0, 0, '+7 Intellect', 'HYBRID/SPELL - ALL - ALL'),
	(105, 60, 80, 0, 0, 0, '+7 Stamina', 'ALL - ALL - ALL'),
	(101, 60, 80, 8, 0, 0, '+7 Spirit', 'SPELL - ALL - ALL'),
	(109, 60, 80, 3, 0, 0, '+7 Strength', 'TANK/PHYS - ALL - ALL'),
	(211, 60, 80, 8, 0, 0, '+7 Spell Power', 'SPELL - ALL - ALL');
	
DROP TABLE IF EXISTS `statbooster_enchant_scores`;
CREATE TABLE IF NOT EXISTS `statbooster_enchant_scores` (
  `mod_type` int(11) DEFAULT NULL,
  `mod_id` int(11) DEFAULT NULL,
  `subclass` int(11) DEFAULT NULL,
  `tank_score` int(11) DEFAULT NULL,
  `phys_score` int(11) DEFAULT NULL,
  `spell_score` int(11) DEFAULT NULL,
  `hybrid_score` int(11) DEFAULT NULL,
  `note` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `statbooster_enchant_scores` (`mod_type`, `mod_id`, `subclass`, `tank_score`, `phys_score`, `spell_score`, `hybrid_score`, `note`) VALUES
	(0, 44, 0, 1, 2, 0, 1, 'ITEM_MOD_ARMOR_PENETRATION_RATING - ALL'),
	(0, 38, 0, 1, 2, 0, 1, 'ITEM_MOD_ATTACK_POWER - ALL'),
	(0, 4, 0, 1, 2, 0, 1, 'ITEM_MOD_STRENGTH - ALL'),
	(0, 3, 0, 1, 2, 0, 1, 'ITEM_MOD_AGILITY - ALL'),
	(0, 5, 1, 0, 0, 1, 0, 'ITEM_MOD_INTELLECT - CLOTH'),
	(0, 5, 2, 0, 0, 1, 1, 'ITEM_MOD_INTELLECT - LEATHER'),
	(0, 5, 3, 1, 0, 1, 1, 'ITEM_MOD_INTELLECT - MAIL'),
	(0, 5, 4, 1, 0, 1, 0, 'ITEM_MOD_INTELLECT - PLATE'),
	(0, 5, 0, 1, 0, 3, 2, 'ITEM_MOD_INTELLECT - ALL'),
	(0, 6, 0, 0, 0, 1, 0, 'ITEM_MOD_SPIRIT - ALL'),
	(0, 43, 0, 0, 0, 1, 0, 'ITEM_MOD_MANA_REGENERATION - ALL'),
	(0, 41, 0, 0, 0, 1, 0, 'ITEM_MOD_SPELL_HEALING_DONE - ALL'),
	(0, 45, 0, 0, 0, 1, 0, 'ITEM_MOD_SPELL_POWER - ALL'),
	(0, 47, 0, 0, 0, 1, 0, 'ITEM_MOD_SPELL_PENETRATION - ALL'),
	(0, 42, 0, 0, 0, 1, 0, 'ITEM_MOD_SPELL_DAMAGE_DONE - ALL'),
	(0, 14, 0, 3, 0, 0, 0, 'ITEM_MOD_PARRY_RATING - ALL'),
	(0, 13, 0, 3, 0, 0, 0, 'ITEM_MOD_DODGE_RATING - ALL'),
	(0, 12, 0, 3, 0, 0, 0, 'ITEM_MOD_DEFENSE_SKILL_RATING - ALL'),
	(0, 15, 0, 3, 0, 0, 0, 'ITEM_MOD_BLOCK_RATING - ALL'),
	(1, 99, 0, 1, 2, 0, 1, 'SPELL_AURA_MOD_ATTACK_POWER - ALL'),
	(1, 135, 0, 0, 0, 0, 1, 'SPELL_AURA_MOD_HEALING_DONE - ALL'),
	(1, 85, 0, 0, 0, 0, 1, 'SPELL_AURA_MOD_POWER_REGEN - ALL'),
	(1, 13, 0, 0, 0, 0, 1, 'SPELL_AURA_MOD_DAMAGE_DONE - ALL');
