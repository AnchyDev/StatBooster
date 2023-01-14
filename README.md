# ![Azeroth Core](https://i.imgur.com/fQwb8m3.png) Stat Booster
## Build Status
|Master|Dev|
|-|-|
| ![Build Status](https://github.com/anchydev/statbooster/actions/workflows/core-build.yml/badge.svg?branch=master) | ![Build Status](https://github.com/anchydev/statbooster/actions/workflows/core-build.yml/badge.svg?branch=dev) |

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
2. **Place** `statbooster.conf.dist` into your server `./configs/modules` directory.

Visit the [Wiki](https://github.com/AnchyDev/StatBooster/wiki/Enchant%20Template) if you require help with setting up enchants in the database.

## Example Items
![Item01](https://i.imgur.com/MYgpZKK.png)
![Item02](https://i.imgur.com/qCgx7XS.png)
![Item03](https://i.imgur.com/nnh3YA1.png)

## Contact
If you would like to help out with the mod or just need help there is a [Discord Server](https://discord.gg/xdVPGcpJ8C) you can join.

## License

This module uses the [MIT](https://github.com/AnchyDev/StatBooster/blob/master/LICENSE) license.

## Credits
- [AzerothCore](https://github.com/azerothcore/azerothcore-wotlk) community for their help with implementing my hooks and creating a great core.
- [3ndos](https://github.com/3ndos) for inspiring this module (and whoever made the original LUA script)!
