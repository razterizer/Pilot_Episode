# Pilot Episode

![GitHub License](https://img.shields.io/github/license/razterizer/Pilot_Episode?color=blue)
![Static Badge](https://img.shields.io/badge/C%2B%2B-20-yellow)

[![build ubuntu](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-ubuntu.yml/badge.svg)](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-ubuntu.yml)
[![build macos](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-macos.yml/badge.svg)](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-macos.yml)
[![build windows](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-windows.yml/badge.svg)](https://github.com/razterizer/Pilot_Episode/actions/workflows/build-windows.yml)
![Valgrind Status](https://raw.githubusercontent.com/razterizer/Pilot_Episode/badges/valgrind-badge.svg)

![Top Languages](https://img.shields.io/github/languages/top/razterizer/Pilot_Episode)
![GitHub repo size](https://img.shields.io/github/repo-size/razterizer/Pilot_Episode)
![C++ LOC](https://raw.githubusercontent.com/razterizer/Pilot_Episode/badges/loc-badge.svg)
![Commit Activity](https://img.shields.io/github/commit-activity/t/razterizer/Pilot_Episode)
![Last Commit](https://img.shields.io/github/last-commit/razterizer/Pilot_Episode?color=blue)
![Contributors](https://img.shields.io/github/contributors/razterizer/Pilot_Episode?color=blue)

![GitHub Downloads (all assets, all releases)](https://img.shields.io/github/downloads/razterizer/Pilot_Episode/total)

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

![ubuntu_cbbbzvqdup_360](https://github.com/user-attachments/assets/133102d0-6125-4218-84a0-118f47ea0a4d)

![ubuntu_gk3dzzntm0_360](https://github.com/user-attachments/assets/49b55e06-7d3c-4bff-8698-7e3ad5225abf)

https://www.youtube.com/watch?v=6ycg91F3Pn4

https://www.youtube.com/watch?v=MCauEDtP2ZU


## Build & Run Instructions

There are two options on dealing with repo dependencies:

### Repo Dependencies Option 1

This method will ensure that you are running the latest stable versions of the dependencies that work with `Pilot_Episode`.

The script `fetch-dependencies.py` used for this was created by [Thibaut Buchert](https://github.com/thibautbuchert).
`fetch-dependencies.py` is used in the following scripts below:

After a successful build, the scripts will then prompt you with the question if you want to run the program.

When the script has been successfully run for the first time, you can then go to sub-folder `Pilot_Episode` and use the `build.sh` / `build.bat` script instead, and after you have built, just run the `run.sh` or `run.bat` script.

#### Windows

Run the following script:
```sh
setup_and_build.bat
```

#### MacOS

Run the following script:
```sh
setup_and_build_macos.sh
```

#### Linux (Debian-based, e.g. Ubuntu)

Run the following script:
```sh
setup_and_build_debian.bat
```

### Repo Dependencies Option 2

In this method we basically outline the things done in the `setup_and_build`-scripts in Option 1.

This method is more suitable for development as we're not necessarily working with "locked" dependencies.

You need the following header-only libraries:
* https://github.com/razterizer/Core
* https://github.com/razterizer/Termin8or
* https://github.com/razterizer/8Beat
* https://github.com/razterizer/AudioLibSwitcher_applaudio
* https://github.com/razterizer/TrainOfThought
* https://github.com/razterizer/applaudio

Make sure the folder structure looks like this:
```
<my_source_code_dir>/lib/Core/                      ; Core repo workspace/checkout goes here.
<my_source_code_dir>/lib/Termin8or/                 ; Termin8or repo workspace/checkout goes here.
<my_source_code_dir>/lib/8Beat/                     ; 8Beat repo workspace/checkout goes here.
<my_source_code_dir>/lib/AudioLibSwitcher_applaudio ; AudioLibSwitcher_applaudio repo workspace/checkout goes here.
<my_source_code_dir>/lib/TrainOfThought             ; TrainOfThought repo workspace/checkout goes here.
<my_source_code_dir>/lib/applaudio                  ; applaudio repo workspace/checkout goes here (only needed for Windows).
<my_source_code_dir>Pilot_Episode/                  ; Pilot_Episode repo workspace/checkout goes here.
```

These repos are not guaranteed to all the time work with the latest version of `Pilot_Episode`. If you want the more stable aproach then look at Option 1 instead.

### Windows

Then just open `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/Pilot_Episode.sln` and build and run. That's it!

You can also build it by going to `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/` and build with `build.bat`.
Then you run by typing `run.bat`.

### MacOS

Then goto `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/` and build with `./build.sh`.

Then run by typing `./bin/pilot_episode`.

### Linux

Then goto `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/` and build with `./build.sh`.

Then run by typing `./bin/pilot_episode`.

## Make New Release

Trigger new release. For example:
```sh
git tag release-1.0.0.0
git push origin release-1.0.0.0
```

If release workflow failed, you can delete the tag and add it again which then retriggers the release workflow. For example::
```sh
# Delete local tag
git tag -d release-1.0.0.0

# Delete remote tag
git push --delete origin release-1.0.0.0

# Re-create the tag locally
git tag release-1.0.0.0

# Push the tag again (this retriggers the workflow)
git push origin release-1.0.0.0
```

But it is best to use the script `retag_release.sh` for such tasks. E.g.:
```sh
./retag_release bump patch "Some tag message."
```
or e.g.:
```sh
./retag_release 1.1.5.7 "Some tag message."
```

Note that the tag message is currently not used as release notes, but the last commit message is. I will change this in the future.

## Running from a Release

When you download a MacOS release then you need to tell the gatekeeper unblock the executable (here: `pilot_episode`), but only if you trust the program of course (check source code + release workflow if you're unsure).
When you feel ready, you can allow the binary to be run by going to the release folder and type the following:

```sh
xattr -dr com.apple.quarantine pilot_episode
```

On Windows, you might have to unblock the exe by right-clicking the exe-file and check the `Unblock` checkbox.
