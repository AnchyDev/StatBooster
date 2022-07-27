# ![Azeroth Core](https://i.imgur.com/fQwb8m3.png) Stat Booster ![Build Status](https://github.com/anchydev/statbooster/actions/workflows/core-build.yml/badge.svg)
⚠️ !! This module is not ready yet, however it is usable in its current state !! ⚠️
## About
This is a module for [Azeroth Core](https://github.com/azerothcore/azerothcore-wotlk) inspired by the [RandomEnchants](https://github.com/azerothcore/mod-random-enchants) module. 
The module will randomly enchant items with stats that compliment the item.
I am developing this module in an attempt to take it in a slightly different direction and to fix bugs that are present in the original module.

This is my first C++ project so any tips are appreciated and welcome! :)

## Features
The features I have planned for this module that differ from the original are:
- **Stat Analysis** - Items are analyzed and enchanted based on stats already on the item. (If there are no stats then it is analyzed based off class & subclass types.)
- **Expandable Enchant Pool** - You can add enchant ids to your database table to expand your pool.
- **Item Level Based** - You can assign item level ranges to enchants in the database table for each entry preventing high level enchants on low level items.
 
## Install
1. **[Clone](https://git-scm.com/docs/git-clone)** this repository into your `./azerothcore-wotlk/modules` folder. (Make sure to clone it into a subdirectory called StatBooster)
2. **Execute** `./sql/world/base/development.sql` on your world database to create the enchant entries.
3. **Place** `statbooster.conf.dist` into your server `./configs/modules` directory.

## Notes
### Enchant Template Table
#### Id
The `Id` column is the enchantment id. You can find enchantment ids by visiting https://wotlkdb.com/?enchantments and selecting an enchant. Your id is visible in the url.

Example: https://wotlkdb.com/?enchantment=74 - Id = 74.
#### iLvlMin/Max
The `iLvlMin` & `iLvlMax` columns are for stating the itemlevel range that your enchant can be applied onto. Both of these column values are inclusive.

#### RoleMask
When adding an entry to the enchant template table you have to provide a value to the `RoleMask` column to appropriately assign enchants to items when analyzed.
To create your RoleMask you need to create a sum of all the roles that are able to use the enchant.
The values for each role are:

- **All**: 0
- **Tank**: 1
- **Phys**: 2
- **Hybrid**: 4
- **Spell**: 8

Example: `Tank + Phys + Hybrid = 7` `Hybrid + Spell = 12`

To have all of the roles use the enchant, set the `RoleMask` to `0`.

#### ClassMask
Like RoleMask you have to create a sum of all of the item classes able to use the enchant.

- **All**: 0
- **Weapon**: 2
- **Armor**: 4

To have all of the classes use the enchant, set the `ClassMask` to `0`.

## Example Items
![Item01](https://i.imgur.com/MYgpZKK.png)
![Item02](https://i.imgur.com/qCgx7XS.png)
![Item03](https://i.imgur.com/nnh3YA1.png)

## Contact
If you would like to help out with the mod or just need help there is a [Discord Server](https://discord.gg/xdVPGcpJ8C) you can join.
