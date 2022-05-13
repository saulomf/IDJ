#include "../include/Face.h"
#include "../include/Sound.h"


Face::Face(GameObject& associated) : Component(associated) {
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints = hitpoints - damage;
    if(hitpoints <= 0){
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