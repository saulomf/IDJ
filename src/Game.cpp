#include "../include/Game.h"
#include <iostream>

using namespace std;

Game* Game::instance = nullptr;

Game& Game::GetInstance(){
    if(instance  !=  nullptr){
        return *instance;
    }
    instance = new Game("Saulo - 160144884",1024,600);
    return *instance;
}

Game::Game(string title, int width, int height){
    if(instance == nullptr) instance = this;

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) !=0 ){
        cout << "Erro " << SDL_GetError() << endl;
        abort();
    }

    if(IMG_Init(IMG_INIT_JPG) == 0){
        cout << "Erro " << SDL_GetError() << endl;
        abort();
    }

    Mix_Init(MIX_INIT_OGG);
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
        cout << "Erro " << SDL_GetError() << endl;
        abort();
    }
    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,  0);
    if (window == nullptr) {
        cout << "Erro " << SDL_GetError() << endl;
        abort();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        cout << "Erro " << SDL_GetError() << endl;
        abort();
    }

    state = new State;
}

Game::~Game(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();

    IMG_Quit();

    SDL_Quit();
}

State& Game::GetState(){
    return *state;
}

SDL_Renderer* Game::GetRenderer(){
    return renderer;
}

void Game::Run(){
    while (state->QuitRequested() == false)
    {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    
}

int main(int argc, char** argv) {
    Game& game = Game::GetInstance();
    game.Run();
    return 0;
}