#ifndef GAME_H
#define GAME_H
#include <windows.h>
#include <iostream>
#include "glew.h"
#include "SDL.h"
#include "Sprite.h"

enum class tila{KAYNNISSA, KIINNI};
enum class suunta{UP, DOWN, LEFT, RIGHT, NONE};

class game
{
    public:
        game(int);

    protected:

    private:
        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;
        void initSystem();
        void processInput();
        tila _omatila;
        suunta _omasuunta;
        Sprite _sprite;
};

#endif // GAME_H
