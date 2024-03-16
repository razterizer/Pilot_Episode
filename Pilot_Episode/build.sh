#!/bin/bash

additional_flags="-I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib -lopenal"
#additional_flags="-I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib -lopenal.1.23.1"
#additional_flags="-I/opt/homebrew/opt/openal-soft/include -L/opt/homebrew/opt/openal-soft/lib /opt/homebrew/opt/openal-soft/lib/libopenal.dylib"


../../lib/Core/build.sh pilot_episode $1 "${additional_flags[@]}"
