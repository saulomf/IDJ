#ifndef SPRITE_H
#define SPRITE_H

#include <string>

#define INCLUDE_SDL_IMAGE 
#include "SDL_include.h"

#include "Component.h"

using namespace std;

class Sprite : public Component {
    private:
        SDL_Texture* texture;
        int width;
        int height;
        SDL_Rect clipRect;

    public:
        Sprite(GameObject& associated);
        Sprite(string file, GameObject& associated);
        ~Sprite();
        void Open(string file);
        void SetClip(int x, int y, int w, int h);
        void Render();
        int GetWidth();
        int GetHeight();
        bool IsOpen();
        void Update(float dt);
        bool Is(string type);
};

#endif