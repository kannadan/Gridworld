#include "GameState.h"
#include <iostream>
using namespace std;

GameState::GameState(int variable)
{
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            for (int z = 0; z< 4; z++){
                board[y][x][z] = 0;
            }
        }
    }
    switch(variable){

    case 1:                 //all pieces at predetermined positions

    board[0][1][0] = 1;     //player
    board[2][2][1] = 1;     //wall
    board[1][1][2] = 1;     //hole
    board[3][3][3] = 1;     //gold

    position[0] = 0;
    position[1] = 1;
    break;
    case 2:                 //player start position varies

    break;
    case 3:                 //all pieces at random start position
    break;
    }
}

GameState::GameState(int old[4][4][4], int oldPosition[2],int direction){       //creates a new gamestate based on move made
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            for (int z = 0; z< 4; z++){
                board[y][x][z] = old[y][x][z];      //copy old state
            }
        }
    }
    position[0] = oldPosition[0];
    position[1] = oldPosition[1];
    switch(direction){
    case 1:
        if (position[0] != 0 && board[position[0]-1][position[1]][1] != 1){
            board[position[0]][position[1]][0] = 0;
            position[0]--;
            board[position[0]][position[1]][0] = 1;
        }
        break;
    case 2:
        if (position[0] != 3 && board[position[0]+1][position[1]][1] != 1){
            board[position[0]][position[1]][0] = 0;
            position[0]++;
            board[position[0]][position[1]][0] = 1;
        }
        break;
    case 3:
        if (position[1] != 0 && board[position[0]][position[1]-1][1] != 1){
            board[position[0]][position[1]][0] = 0;
            position[1]--;
            board[position[0]][position[1]][0] = 1;
        }
        break;
    case 4:
        if (position[1] != 3 && board[position[0]][position[1]+1][1] != 1){
            board[position[0]][position[1]][0] = 0;
            position[1]++;
            board[position[0]][position[1]][0] = 1;
        }

    }

}

void GameState::printBoard(){
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            for (int z = 0; z< 4; z++){
                cout << board[y][x][z];
            }
            cout << "  ";
        }
        cout << endl;
    }

}

int GameState::endGame(){
    if (position[0] == 3 && position[1] == 3){
        return 1;
    }
    else if (position[0] == 1 && position[1] == 1){
        return 2;
    }
    else{
        return 0;
    }

}

void GameState::updateWindow(){             //goes through the board and generates 2d matrix for display purposes
    for(int y = 0; y<4; y++){
        for(int x = 0; x < 4; x++){
            for(int z = 0; z < 4; z++){
                if (board[y][x][z] == 1){
                    switch(z){                  //P = player W = wall, - = hole and + = gold
                    case 0:
                        window[y][x] = 'P';
                        break;
                    case 1:
                        window[y][x] = 'W';
                        break;
                    case 2:
                        window[y][x] = '-';
                        break;
                    case 3:
                        window[y][x] = '+';
                    }
                    break;

                }
                else{
                    window[y][x] = ' ';
                }
            }
        }
    }
}

GameState GameState::makeMove(int command){

    GameState newState(board, position, command);
    return newState;

}
void GameState::printWindow(){
    updateWindow();
    for (int y = 0; y < 4; y++){
        for (int x = 0; x < 4; x++){
            cout << "[" + window[y][x] + "]";
            cout << "  ";
        }
        cout << endl;
    }


}

