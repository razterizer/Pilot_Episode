#!/bin/bash

#g++ pilot_episode.cpp -lSDL2 -o pilot_episode
#g++ pilot_episode.cpp -lncurses -o pilot_episode
#export XDG_RUNTIME_DIR=/tmp
echo "Building for Linux / MacOS target..."
mkdir -p bin_linux
g++ pilot_episode.cpp -o ./bin_linux/pilot_episode -std=c++2a -O3
echo "Done."
#./pilot_episode

#################
# Windows build #
#################

echo "Building for Windows target via mingw..."
mkdir -p bin_windows
x86_64-w64-mingw32-g++ -Wl,--stack,10000000 pilot_episode.cpp -o ./bin_windows/pilot_episode.exe -std=c++2a -O3
echo "Done."

echo "Copying Windows/mingw related dlls..."
# Paths to the found DLLs
#DLL_PATH_1="/System/Volumes/Data/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-x86_64/x86_64-w64-mingw32/lib/libstdc++-6.dll"
#DLL_PATH_2="/System/Volumes/Data/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-x86_64/x86_64-w64-mingw32/lib/libgcc_s_seh-1.dll"
#/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-i686/i686-w64-mingw32/bin/libwinpthread-1.dll
#/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-x86_64/x86_64-w64-mingw32/bin/libwinpthread-1.dll
DLL_PATH_1="/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-x86_64/x86_64-w64-mingw32/lib/libstdc++-6.dll"
DLL_PATH_2="/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-x86_64/x86_64-w64-mingw32/lib/libgcc_s_seh-1.dll"
DLL_PATH_3="/opt/homebrew/Cellar/mingw-w64/11.0.1/toolchain-x86_64/x86_64-w64-mingw32/bin/libwinpthread-1.dll"

if [ -f "$DLL_PATH_1" ] && [ -f "$DLL_PATH_2" ] && [ -f "$DLL_PATH_3" ]; then
  cp "$DLL_PATH_1" ./bin_windows
  cp "$DLL_PATH_2" ./bin_windows
  cp "$DLL_PATH_3" ./bin_windows
else
  echo "DLLs not found. Please provide correct paths."
fi
echo "Done."
