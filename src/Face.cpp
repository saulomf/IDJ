#include "../include/Face.h"
#include "../include/Sound.h"
#include <iostream>
using namespace std;

Face::Face(GameObject& associated) : Component(associated) {
    hitpoints = 30;
}

void Face::Damage(int damage){
    damage += 1000000;
    cout<<damage<<endl;
    cout<<hitpoints<<endl;
    hitpoints = hitpoints - damage;
    if(hitpoints <= 0){
        Sound* sound = (Sound*) associated.GetComponent( "Sound" );
        if ( nullptr != sound ) {
            sound->Play();
        }
        this->associated.RequestDelete();
    }
}

void Face::Update(float dt){
    
}

void Face::Render(){
    
}

bool Face::Is (string type){
    if(type == "Face") return true;
    return false;
}