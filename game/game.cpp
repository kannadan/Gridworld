#include "game.h"
#include "GameState.h"
#include <iostream>
#include <windows.h>



using namespace std;


game::game(int variable)
{
    _omatila = tila::KAYNNISSA;
    _omasuunta = suunta::NONE;
    switch(variable){

        case 0:         // no graphics
        {

        GameState state(1);
        int a = 0;
        int dir;
        state.printWindow();
        while (a < 1){
            cout << "make a move \n";
            cin >> dir;
            state = state.makeMove(dir);
            if (dir == 5){
                break;
            }
            state.printWindow();
        }
        break;
        }
        case 1:         // graphics
        initSystem();
        GameState state(1);
        int a = 0;
        int dir;
        state.printWindow();
        while (_omatila == tila::KAYNNISSA){
            processInput();
            if (_omasuunta != suunta::NONE){
                switch (_omasuunta){
                    case suunta::UP:
                        dir = 1;
                        break;
                    case suunta::DOWN:
                        dir = 2;
                        break;
                    case suunta::LEFT:
                        dir = 3;
                        break;
                    case suunta::RIGHT:
                        dir = 4;
                        break;
                }
                state = state.makeMove(dir);
                state.printWindow();
                cout << "\n";
                _omasuunta = suunta::NONE;
            }
            if (state.endGame() != 0){
                _omatila = tila::KIINNI;
                if (state.endGame() == 1){
                    cout << "Voitit pelin";
                }
                else{
                    cout << "Hävisit pelin";
                }
            }
        }
    }
}


void game::initSystem(){        // mainly initializes graphics stuff
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight  = 600;
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("GridWorld", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);


}

void game::processInput(){
    SDL_Event act;

    while(SDL_PollEvent(&act)){
        switch(act.type){

            case SDL_QUIT:
                _omatila = tila::KIINNI;
                break;
            case SDL_MOUSEMOTION:
                break;

            case SDL_KEYDOWN:
                switch (act.key.keysym.sym){
                    case SDLK_UP:
                        _omasuunta = suunta::UP;
                        break;
                    case SDLK_DOWN:
                        _omasuunta = suunta::DOWN;
                        break;
                    case SDLK_LEFT:
                        _omasuunta = suunta::LEFT;
                        break;
                    case SDLK_RIGHT:
                        _omasuunta = suunta::RIGHT;
                        break;
                }

                break;


        }

    }
}









