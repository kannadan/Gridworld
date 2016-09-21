#include "game.h"
#include "GameState.h"
using namespace std;

game::game(int variable)
{
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
    break;
    }
}
