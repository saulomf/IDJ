#include "../include/Game.h"

State::State(){
    quitRequested = false;
    bg = new Sprite("./assets/img/ocean.jpg");
    music = new Music("./assets/audio/stageState.ogg");
    music->Play();
}

void State::LoadAssets(){

}

void State::Update(float dt){
    if(SDL_QuitRequested()){
        quitRequested = true;
    }
}

void State::Render(){
    bg->Render(0,0);
}

bool State::QuitRequested(){
    return quitRequested;
}