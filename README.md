# Pilot Episode

![GitHub License](https://img.shields.io/github/license/razterizer/Pilot_Episode?color=blue)

[![build check ubuntu](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-ubuntu.yml/badge.svg)](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-ubuntu.yml)
[![build check macos](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-macos.yml/badge.svg)](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-macos.yml)
[![build check windows](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-windows.yml/badge.svg)](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-windows.yml)

![Top Languages](https://img.shields.io/github/languages/top/razterizer/Pilot_Episode)
<!-- ![Languages](https://img.shields.io/github/languages/count/razterizer/Pilot_Episode) -->
![Goto](https://img.shields.io/github/search/razterizer/Pilot_Episode/goto)
![Commit Activity](https://img.shields.io/github/commit-activity/t/razterizer/Pilot_Episode)
![Last Commit](https://img.shields.io/github/last-commit/razterizer/Pilot_Episode?color=blue)
![Contributors](https://img.shields.io/github/contributors/razterizer/Pilot_Episode?color=blue)

## Licensing

For 3rd-party license-compatibilities, please refer to the information here: https://github.com/razterizer/8Beat/blob/main/README.md

## About the Game

A cross-platform (Lin/Mac/Win) terminal-based shooter game.

![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/9b596d5c-e128-4dba-8fb5-02e9b3d8f412)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/1a5f06e8-130b-4e6b-a96c-915e61bcd73d)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/d8cba740-fe6e-4d59-9c9f-308a0bb40d67)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/abd78df7-7314-43a2-8ef6-0270dc979575)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/89a0443d-8d90-4630-aa8a-5c84b774e8f8)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/e46094ff-bb92-43da-ba7d-28eb5a3c5730)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/7230fefa-5b50-4107-9a73-d274c1d629c2)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/16977fe1-330b-4b41-bfc3-5793161034f4)
![image](https://github.com/razterizer/Pilot_Episode/assets/32767250/18ba7d45-6b5c-42ba-9cce-c233609ce947)

https://www.youtube.com/watch?v=6ycg91F3Pn4

https://www.youtube.com/watch?v=MCauEDtP2ZU


## Build & Run Instructions

There are two options on dealing with repo dependencies:
### Repo Dependencies Option 1

Run the following command from `<my_source_code_dir>`.
```sh
./Pilot_Episode/fetch-dependencies ./Pilot_Episode/dependencies
```
This will make sure you are running the latest stable versions that work with `Pilot_Episode`.

This script was created by [Thibaut Buchert](https://github.com/thibautbuchert).

### Repo Dependencies Option 2

You need the following header-only libraries that I've made:
* https://github.com/razterizer/Core
* https://github.com/razterizer/Termin8or
* https://github.com/razterizer/8Beat
* https://github.com/razterizer/AudioLibSwitcher_OpenAL ; Will be changed to something like AudioLibSwitcher_libsoundio in the future.

Make sure the folder structure looks like this:
```
<my_source_code_dir>/lib/Core/                   ; Core repo workspace/checkout goes here.
<my_source_code_dir>/lib/Termin8or/              ; Termin8or repo workspace/checkout goes here.
<my_source_code_dir>/lib/8Beat/                  ; 8Beat repo workspace/checkout goes here.
<my_source_code_dir>/lib/AudioLibSwitcher_OpenAL ; AudioLibSwitcher_OpenAL repo workspace/checkout goes here.
<my_source_code_dir>Pilot_Episode/               ; Pilot_Episode repo workspace/checkout goes here.
```

These repos are not guaranteed to all the time work with the latest version of `Pilot_Episode`. If you want the more stable aproach then look at Option 1 instead.

### Windows

You also need the following 3rdparty folder with subfolders:
```
<my_source_code_dir>/lib/3rdparty/
<my_source_code_dir>/lib/3rdparty/include/
<my_source_code_dir>/lib/3rdparty/include/OpenAL_Soft/
<my_source_code_dir>/lib/3rdparty/lib/
```

`<my_source_code_dir>/lib/3rdparty/lib/` should contain:
* `OpenAL32.lib`.

`<my_source_code_dir>/lib/3rdparty/include/OpenAL_Soft/` should contain:
* `al.h`.
* `alc.h`.
* `alext.h`.
* `efx.h`.
* `efx-creative.h`.
* `efx-presets.h`.

I will change the audio library to something like `libsoundio` in the future though for licensing reasons.

Then just open `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/Pilot_Episode.sln` and build and run. That's it!

### MacOS

Make sure you have OpenAL-Soft installed: `brew install openal-soft`.

Then goto `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/` and build with `./build.sh`.

Then run by typing `./bin_linux/pilot_episode`.

### Linux (Ubuntu)

Make sure you have OpenAL-Soft installed: `sudo apt install libopenal-dev`.

Then goto `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/` and build with `./build.sh`.

Then run by typing `./bin_linux/pilot_episode`.
