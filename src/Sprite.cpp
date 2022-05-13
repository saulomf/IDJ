#include "../include/Game.h"

#include <iostream>

using namespace std;

Sprite::Sprite(GameObject& associated) : Component(associated){
    texture = nullptr;
}

Sprite::Sprite(string file, GameObject& associated) : Component(associated){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    if(IsOpen()) SDL_DestroyTexture(texture);
}

void Sprite::Open(string file){
    if(IsOpen()) SDL_DestroyTexture(texture);
    texture = nullptr;
    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if(texture == nullptr){
        cout << "erro " << SDL_GetError() << endl;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(){
    SDL_Rect dstrect;
    dstrect.x = associated.box.x;
    dstrect.y = associated.box.y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    if (texture != nullptr) return true;
    return false;
}

void Sprite::Update(float dt){

}

bool Sprite::Is(string type){
    if(type == "Sprite") return true;
    return false;
}