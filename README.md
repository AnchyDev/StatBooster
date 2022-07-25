# ![Azeroth Core](https://i.imgur.com/fQwb8m3.png) Stat Booster
⚠️ !! This module is not ready yet, however it is usable in its current state !! ⚠️
## About
This is a module for [Azeroth Core](https://github.com/azerothcore/azerothcore-wotlk) inspired by the [RandomEnchants](https://github.com/azerothcore/mod-random-enchants) module. 
The module will randomly enchant items with stats that compliment the item.
I am developing this module in an attempt to take it in a slightly different direction and to fix bugs that are present in the original module.

This is my first C++ project so any tips are appreciated and welcome! :)

## Features
The features I have planned for this module that differ from the original are:
- Stat Analysis - Items are analyzed and enchanted based on stats already on the item. (If there are no stats then it is analyzed based off class & subclass types.)
 
## Install
1. Execute `statbooster_enchant_template.sql` on your world database to create the enchant entries.
2. [Patch](https://git-scm.com/docs/git-apply) your core with `patch01.patch`.
3. Place `statbooster.conf.dist` into your server `./configs/modules` directory.
4. [Clone](https://git-scm.com/docs/git-clone) this repository into your `./azerothcore-wotlk/modules` folder. (Make sure to clone it into a subdirectory called StatBooster)

## Example Items
![Item01](https://i.imgur.com/MYgpZKK.png)
![Item02](https://i.imgur.com/qCgx7XS.png)
![Item03](https://i.imgur.com/nnh3YA1.png)

## Contact
If you would like to help out with the mod or just need help there is a [Discord Server](https://discord.gg/xdVPGcpJ8C) you can join.
