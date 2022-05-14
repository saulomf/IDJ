#include "../include/Game.h"
#include "../include/Sound.h"
#include "../include/Face.h"
#include <iostream>

State::State(){
    quitRequested = false;
    GameObject* bg = new GameObject();
    bg->AddComponent(new Sprite("./assets/img/ocean.jpg",*bg));
    objectArray.emplace_back(bg);
    music = new Music("./assets/audio/stageState.ogg");
    music->Play();
}

State::~State(){
    objectArray.clear();
}

void State::Input(){
    SDL_Event event;
    int mouseX, mouseY;

	SDL_GetMouseState(&mouseX, &mouseY);
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) quitRequested = true;
        if(event.type == SDL_MOUSEBUTTONDOWN){
            for(int i = objectArray.size() - 1; i >= 0; --i) {
                GameObject* go = (GameObject*) objectArray[i].get();

				if(go->box.isIn( Vec2((float) mouseX, (float) mouseY) )) {
					Face* face = (Face*) go->GetComponent( "Face" );
					if ( nullptr != face ) {
						face->Damage(rand() % 10 + 10);
						break;
					}
				}
            }
        }
        if(event.type == SDL_KEYDOWN){
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
				quitRequested = true;
			} else {
				Vec2 objPos1 = Vec2( 200, 0 ).rotated( -3.14 + 3.14*(rand() % 1001)/500.0 );
                Vec2 objPos2 = Vec2( mouseX, mouseY );
                objPos1.opPlus(objPos2);
				AddObject((int)objPos1.x, (int)objPos1.y);
			}
        }
    }
}

void State::AddObject (int mouseX, int mouseY){
    GameObject* enemy = new GameObject();

    Sprite* sprite = new Sprite("./assets/img/penguinface.png", *enemy);
    enemy->box.x = mouseX - enemy->box.w / 2;
    enemy->box.y = mouseY - enemy->box.h / 2;

	Sound* sound = new Sound("./assets/audio/boom.wav", *enemy);

    Face* face = new Face(*enemy);


    enemy->AddComponent(sprite);
	enemy->AddComponent(sound);
    enemy->AddComponent(face);

    objectArray.emplace_back(enemy);
}

void State::LoadAssets(){

}

void State::Update(float dt){
    Input();
    for(unsigned int i=0; i<objectArray.size(); i++) {
        objectArray[i]->Update(dt);
    }

    for(unsigned int i=0; i<objectArray.size(); i++) {
        if(objectArray[i]->IsDead()) {
            objectArray.erase(objectArray.begin() + i);
        }
    }
}

void State::Render(){
    for(unsigned int i = 0; i < objectArray.size(); i++){
        objectArray[i].get()->Render();
    }
}

bool State::QuitRequested(){
    return quitRequested;
}