#ifndef GAMESTATE_H
#define GAMESTATE_H


class GameState
{
    public:
        GameState(int);
        int getBoard();
        char getWindow();
        void makeMove();
        bool gameOver();

    protected:

    private:
        int board[4][4][4];         // 3d representation of the board that is 4x4 in size and the third dimension tells what is on the board. fed in to the neural network.
        char window[4][4];          // simpler representation of the board that is shown to user
        int position[2];    // info on the player position
};

#endif // GAMESTATE_H
