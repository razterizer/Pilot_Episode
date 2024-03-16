# Pilot Episode
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

