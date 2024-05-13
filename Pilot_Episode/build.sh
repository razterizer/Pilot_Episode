#!/bin/bash

os_name=$(uname)

if [[ $os_name == *"Darwin"* ]]; then
  additional_flags="-I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib -lopenal.1.23.1"
else
  additional_flags=""
fi
#additional_flags="-I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib -lopenal.1.23.1"
#additional_flags="-I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib /opt/homebrew/opt/openal-soft/lib/libopenal.dylib"

export BUILD_PKG_CONFIG_MODULES='openal'

../../lib/Core/build.sh pilot_episode "$1" "${additional_flags[@]}"
