# Pilot Episode
A cross-platform (Lin/Mac/Win) terminal-based shooter game.

## Build & Run Instructions

You need the following header-only libraries that I've made:
* https://github.com/razterizer/Core
* https://github.com/razterizer/Consolation
* https://github.com/razterizer/8Beat

Make sure the folder structure looks like this:
```
<my_source_code_dir>/lib/Core               ; Core repo workspace/checkout goes here.
<my_source_code_dir>/lib/Consolation        ; Consolation repo workspace/checkout goes here.
<my_source_code_dir>/lib/8Beat              ; 8Beat repo workspace/checkout goes here.
<my_source_code_dir>Pilot_Episode           ; Pilot_Episode repo workspace/checkout goes here.
```
### Windows

Then just open `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/Pilot_Episode.sln` and build and run. That's it!

### MacOS

Make sure you have OpenAL-Soft installed: `brew install openal-soft`.
Then goto `<my_source_code_dir>/Pilot_Episode/Pilot_Episode/` and build with `./build.sh l`.
Then run by typing `./bin_linux/pilot_episode`.

