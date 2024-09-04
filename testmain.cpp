#include "IO.h"
#include "Game.h"
#include "Piece.h"
#include <iostream>

int main(int argc, char *argv[])
{
    IO mIO;
    int mScreenHeight = mIO.getScreenHeight();
    Piece mPieces = Piece();
    Board mBoard(&mPieces, mScreenHeight);
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);
    

    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true; // Exit the loop when the window is closed
            }
        }
    }
    return 0;
}