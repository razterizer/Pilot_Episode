#g++ pilot_episode.cpp -lSDL2 -o pilot_episode
#g++ pilot_episode.cpp -lncurses -o pilot_episode
#export XDG_RUNTIME_DIR=/tmp
g++ pilot_episode.cpp -o pilot_episode -std=c++2a -O3
#./pilot_episode
x86_64-w64-mingw32-g++ pilot_episode.cpp -o pilot_episode.exe -std=c++2a -O3
