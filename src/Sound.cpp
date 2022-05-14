#include "../include/Sound.h"
#include <iostream>

using namespace std;

Sound::Sound(GameObject& associated) : Component(associated){
    chunk = nullptr;
}

Sound::Sound(string file, GameObject& associated) : Sound(associated){
    Open(file);
}

Sound::~Sound(){
    
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, times);
    if(channel == -1) {
        cout << "Erro 2222 " << SDL_GetError() << endl;
        abort();
    }
}

void Sound::Stop(){
    if(IsOpen())
        Mix_HaltChannel(channel);
} 

void Sound::Open(string file){
    chunk = Mix_LoadWAV(file.c_str());
    if(!IsOpen()){
        cout << "Erro 3333 " << SDL_GetError() << endl;
        abort();
    }
} 

bool Sound::IsOpen(){
    if(chunk == nullptr) return false;
    return true;
}

void Sound::Update(float dt){
    
} 

void Sound::Render(){
    
} 

bool Sound::Is(string type){
    if (type == type) return true;
    return false;
} 