-- --------------------------------------------------------
-- Host:                         127.0.0.1
-- Server version:               8.0.29 - MySQL Community Server - GPL
-- Server OS:                    Win64
-- HeidiSQL Version:             12.0.0.6468
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

-- Dumping structure for table acore_world.statbooster_enchant_template
CREATE TABLE IF NOT EXISTS `statbooster_enchant_template` (
  `Id` int DEFAULT NULL,
  `iLvlMin` int DEFAULT NULL,
  `iLvlMax` int DEFAULT NULL,
  `RoleMask` int DEFAULT NULL,
  `Description` varchar(50) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `Note` varchar(50) COLLATE utf8mb4_general_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- Dumping data for table acore_world.statbooster_enchant_template: ~8 rows (approximately)
INSERT INTO `statbooster_enchant_template` (`Id`, `iLvlMin`, `iLvlMax`, `RoleMask`, `Description`, `Note`) VALUES
	(68, 1, 20, 3, '+1 Strength', 'TANK/PHYS'),
	(74, 1, 20, 7, '+1 Agility', 'TANK/PHYS/HYBRID'),
	(79, 1, 20, 12, '+1 Intellect', 'HYBRID/SPELL'),
	(206, 1, 20, 8, '+1 Spell Power', 'SPELL'),
	(66, 1, 20, 0, '+1 Stamina', 'ALL'),
	(82, 1, 20, 8, '+1 Spirit', 'SPELL'),
	(75, 10, 30, 7, '+2 Agility', 'TANK/PHYS/HYBRID'),
	(69, 10, 30, 3, '+2 Strength', 'TANK/PHYS'),
	(80, 10, 30, 12, '+2 Intellect', 'HYBRID/SPELL'),
	(72, 10, 30, 0, '+2 Stamina', 'ALL'),
	(83, 10, 30, 8, '+2 Spirit', 'SPELL'),
	(207, 10, 30, 8, '+2 Spell Power', 'SPELL'),
	(76, 20, 40, 7, '+3 Agility', 'TANK/PHYS/HYBRID'),
	(81, 20, 40, 12, '+3 Intellect', 'HYBRID/SPELL'),
	(73, 20, 40, 0, '+3 Stamina', 'ALL'),
	(64, 20, 40, 8, '+3 Spirit', 'SPELL'),
	(70, 20, 40, 3, '+3 Strength', 'TANK/PHYS'),
	(2910, 20, 40, 8, '+3 Spell Power', 'SPELL');

/*!40103 SET TIME_ZONE=IFNULL(@OLD_TIME_ZONE, 'system') */;
/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
