#include "game.h"
#include "GameState.h"
using namespace std;

game::game(int variable)
{
    _window = nullptr;
    _screenWidth = 1024;
    _screenHeight  = 600;

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
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("GridWorld", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);


    break;
    }
}
