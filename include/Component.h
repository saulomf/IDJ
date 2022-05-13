#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "GameObject.h"

class GameObject;

using namespace std;

class Component {
    protected:
        GameObject& associated;

    public:
        explicit Component(GameObject& associated) : associated(associated) {};
        virtual ~Component();
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
        virtual bool Is(string type) = 0;
};

#endif