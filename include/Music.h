#ifndef MUSIC_H
#define MUSIC_H

#include <string>

#define INCLUDE_SDL_MIXER 
#include "SDL_include.h"

using namespace std;

class Music{
    private:
        Mix_Music* music;

    public:
        Music();
        Music(string file);
        ~Music();
        void Play(int times = -1);
        void Stop(int msToStop = 1500);
        void Open(string file);
        bool IsOpen();
};

#endif