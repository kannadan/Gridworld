#include "GameState.h"

GameState::GameState(int variable)
{
    switch(variable){

    case 1:                 //all pieces at predetermined positions
    board = {{{0,0,0,0},{1,0,0,0},{0,0,0,0},{0,0,0,0}},
            {{0,0,0,0},{0,0,1,0},{0,0,0,0},{0,0,0,0}},      // (player, wall, hole, gold)
            {{0,0,0,0},{0,0,0,0},{0,1,0,0},{0,0,0,0}},      // make it work
            {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1}}};
    position = {0, 1};
    break;
    case 2:                 //player start position varies

    break;
    case 3:                 //all pieces at random start position

    }
}

GameState::getBoard(){
    return board;
}

GameState::getWindow(){             //goes through the board and generates 2d matrix for display purposes
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

                }
                else{
                    window[y][x] = ' ';
                }
            }
        }
    }
    return window;
}

GameState::makeMove(int move){

    switch(move){
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
        if (position[1] != 0 && board[position[0]-1][position[1]][1] != 1){
            board[position[0]][position[1]][0] = 0;
            position[1]--;
            board[position[0]][position[1]][0] = 1;
        }
        break;
    case 4:
        if (position[1] != 3 && board[position[0]+1][position[1]][1] != 1){
            board[position[0]][position[1]][0] = 0;
            position[1]++;
            board[position[0]][position[1]][0] = 1;


    }





}

