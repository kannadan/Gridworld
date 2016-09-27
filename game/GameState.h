#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <iostream>





class GameState
{
    public:
        GameState(int);
        GameState(int[4][4][4], int[2], int);
        void updateWindow();
        GameState makeMove(int);
        bool gameOver();
        void printBoard();
        void printWindow();
        int endGame();

    protected:

    private:
        int board[4][4][4];         // 3d representation of the board that is 4x4 in size and the third dimension tells what is on the board. fed in to the neural network.
        std::string window[4][4];          // simpler representation of the board that is shown to user
        int position[2];    // info on the player position
};

#endif // GAMESTATE_H
