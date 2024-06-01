#!/bin/bash

os_name=$(uname)

if [[ $os_name == *"Darwin"* ]]; then
  additional_flags="-I../../lib \
  -I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib -lopenal.1.23.1"
else
  additional_flags=""
  export BUILD_PKG_CONFIG_MODULES='openal'
fi

../../lib/Core/build.sh pilot_episode "$1" "${additional_flags[@]}"
