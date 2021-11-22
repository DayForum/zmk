   # Zephyr™ Mechanical Keyboard (ZMK) Firmware

[![Discord](https://img.shields.io/discord/719497620560543766)](https://zmk.dev/community/discord/invite)
[![Build](https://github.com/zmkfirmware/zmk/workflows/Build/badge.svg)](https://github.com/zmkfirmware/zmk/actions)
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg)](CODE_OF_CONDUCT.md)

[ZMK Firmware](https://zmk.dev/) is an open source (MIT) keyboard firmware built on the [Zephyr™ Project](https://www.zephyrproject.org/) Real Time Operating System (RTOS). ZMK's goal is to provide a modern, wireless, and powerful firmware free of licensing issues.

Check out the website to learn more: https://zmk.dev/

You can also come join our [ZMK Discord Server](https://zmk.dev/community/discord/invite)

To review features, check out the [feature overview](https://zmk.dev/docs/). ZMK is under active development, and new features are listed with the [enhancement label](https://github.com/zmkfirmware/zmk/issues?q=is%3Aissue+is%3Aopen+label%3Aenhancement) in GitHub. Please feel free to add 👍 to the issue description of any requests to upvote the feature.

------------------

### ZMK Firmware for [corne](https://github.com/foostan/crkbd) and [jorne](https://github.com/joric/jorne) keyboards with custom OLED modules and custom 5-layers layout. 

Ready at this moment:

Legend:	 | ✅ Supported | 💡 Under Development| 🚧 Possibility
------------ | ------------ | -------------| -------------

Progress | Corne
------------ | -------------
Remaping  | ✅
Rework Layer module to CPM  | ✅
Fix WPM module  | ✅
Rework WPM module to CPM  | ✅
Rework Battery module (add checking if the battery is installed) | 🚧
Rotate screen  | ✅
Porting QMK OLED module bongo_cat | 💡
Rework bongo_cat module | 💡
Porting QMK OLED module randomizer | 💡
Position the modules correctly on the display | ✅
Auto ping pong between sides | 🚧
Keyboard settings menu for oled | 💡