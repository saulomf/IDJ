#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <memory>
#include <string>
#include "Component.h"
#include "Geometry.h"

class Component;

using namespace std;

class GameObject {
    private:
        vector<unique_ptr<Component>> components;
        bool isDead;

    public:
        GameObject();
        ~GameObject();
        void Update(float dt);
        void Render();
        bool IsDead();
        void RequestDelete();
        void AddComponent(Component* cpt);
        void RemoveComponent(Component* cpt);
        Component* GetComponent(string type);
        Rect box;
};

#endif