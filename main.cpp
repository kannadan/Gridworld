#include <windows.h>
#include <iostream>
#include "SDL.h"
#include "glew.h"
#include "game/GameState.h"

using namespace std;

int main(int argc, char** argv)
{
    int SDL_init(SDL_INIT_EVERYTHING);
    /*GameState state(1);
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
    }*/

    return 0;
}
