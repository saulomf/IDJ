#include "../include/Game.h"
#include <iostream>

Music::Music(){
    music = nullptr;
}

Music::Music(string file){
    Open(file);
}

void Music::Play(int times){
    if(music != nullptr)
        Mix_PlayMusic(music,times);
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    music = Mix_LoadMUS(file.c_str());
    if(music == nullptr){
        //SDL_Log("Unable to load music: %s", SDL_GetError());
        cout << "erro: " << SDL_GetError() << endl;
    }
}

bool Music::IsOpen(){
    if(music != nullptr) return true;
    return false;
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}
