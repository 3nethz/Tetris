#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "Piece.h"
#include "time.h"
#include "IO.h"
#include <cstdlib>

class Game
{
public:
    Game(Board *pBoard, Piece *pPiece, IO *pIO, int pScreenHeight);

    void drawScene();
    void createNewPiece();

    int mPositionX, mPositionY;
    int mPiece, mRotation;

private:
    int mScreenHeigt;
    int mNextPositionX, mNextPositionY;
    int mNextPiece, mNextRotation;

    Board *mBoard;
    Piece *mPiece;
    // IO *mIO;

    int getRand(int pA, int pB);
    void initGame();
    void drawPiece(int pY, int pX, int pPiece, int pRotation);
    void drawBoard();
};

int Game::getRand(int pA, int pB)
{
    return rand() % (pB - pA + 1) + pA;
}

#endif // _GAME_