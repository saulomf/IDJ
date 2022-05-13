#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <memory>

#include "GameObject.h"
#include "Sprite.h"
#include "Music.h"

using namespace std;

class State {
    private:
        Music* music;
        bool quitRequested;
        void Input();
        void AddObject (int mouseX, int mouseY);
        vector<unique_ptr<GameObject>> objectArray;

    public:
        State();
        ~State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
};

#endif