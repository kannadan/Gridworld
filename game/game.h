#ifndef GAME_H
#define GAME_H
#include <windows.h>
#include <iostream>
#include "glew.h"
#include "SDL.h"


class game
{
    public:
        game(int);

    protected:

    private:
        SDL_Window* _window;
        int _screenWidth;
        int _screenHeight;
};

#endif // GAME_H
