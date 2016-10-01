#ifndef GAME_H
#define GAME_H
#define GLEW_STATIC
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
        game();
        void run();
        void runG();

    protected:

    private:
        SDL_Window* _window;
        int _dir;
        int _screenWidth;
        int _screenHeight;
        void initSystem();
        void processInput();
        void fatalError(std::string);
        void drawGame();
        tila _omatila;
        suunta _omasuunta;
        Sprite _sprite;
};

#endif // GAME_H
