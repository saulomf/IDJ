#ifndef SOUND_H
#define SOUND_H

#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"

class Sound : public Component {
    private:
        Mix_Chunk* chunk;
        int channel;
    
    public:
        Sound(GameObject& associated);
        Sound(string file, GameObject& associated);
        ~Sound();
        void Play(int times = 1);
        void Stop(); 
        void Open(string file); 
        bool IsOpen();
        void Update(float dt); 
        void Render(); 
        bool Is(string type); 
};

#endif