#ifndef GAME_H
#define GAME_H

#include <string>

#define INCLUDE_SDL 
#define INCLUDE_SDL_IMAGE 
#define INCLUDE_SDL_MIXER 
#define INCLUDE_SDL_TTF 
#include "SDL_include.h"

using namespace std;

#include "State.h"

class Game {
    private:
        Game(string title, int width, int height);
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;

    public:
        ~Game();
        void Run();
        SDL_Renderer* GetRenderer();
        State& GetState();
        static Game& GetInstance();
};

#endif