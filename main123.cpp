#include "Game.h"
#ifndef LINUX
#include "windows.h"
#endif

const int TARGET_FPS = 30;
const int FRAME_DELAY = 1000 / TARGET_FPS;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    IO mIO;
    int mScreenHeight = mIO.getScreenHeight();
    Piece mPieces = Piece();
    Board mBoard(&mPieces, mScreenHeight);
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    unsigned long mTime1 = SDL_GetTicks();

    while (!mIO.isKeyDown(SDLK_ESCAPE))
    {
        unsigned long frameStart = SDL_GetTicks(); // Start of the frame
        mIO.clearScreen();
        mGame.drawScene();
        mIO.updateScreen();

        // input
        int mKey = mIO.pollKey();

        switch (mKey)
        {
        case (SDLK_RIGHT):
        {
            if (mBoard.isPossibleMovement(mGame.mPosX + 1,
                                          mGame.mPosY,
                                          mGame.mPiece,
                                          mGame.mRotation))
                mGame.mPosX++;
            break;
        }
        case (SDLK_LEFT):
        {
            if (mBoard.isPossibleMovement(mGame.mPosX - 1,
                                          mGame.mPosY,
                                          mGame.mPiece,
                                          mGame.mRotation))
                mGame.mPosX--;
            break;
        }
        case (SDLK_DOWN):
        {
            if (mBoard.isPossibleMovement(mGame.mPosX,
                                          mGame.mPosY + 1,
                                          mGame.mPiece,
                                          mGame.mRotation))
                mGame.mPosY++;
            break;
        }
        case (SDLK_x):
        {
            while (mBoard.isPossibleMovement(mGame.mPosX,
                                             mGame.mPosY,
                                             mGame.mPiece,
                                             mGame.mRotation))
            {
                mGame.mPosY++;
            }

            mBoard.storePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);

            mBoard.deletePossibleLines();

            if (mBoard.isGameOver())
            {
                mIO.getKey();
                exit(0);
            }

            mGame.createNewPiece();
            break;
        }
        case (SDLK_z):
        {
            if (mBoard.isPossibleMovement(mGame.mPosX,
                                          mGame.mPosY,
                                          mGame.mPiece,
                                          (mGame.mRotation + 1) % 4))
                mGame.mRotation = (mGame.mRotation + 1) % 4;
            break;
        }
        }

        unsigned long mTime2 = SDL_GetTicks();
        if ((mTime2 - mTime1) > WAIT_TIME)
        {
            if (mBoard.isPossibleMovement(mGame.mPosX,
                                          mGame.mPosY + 1,
                                          mGame.mPiece,
                                          mGame.mRotation))
            {
                mGame.mPosY++;
            }
            else
            {
                mBoard.storePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);

                mBoard.deletePossibleLines();

                if (mBoard.isGameOver())
                {
                    mIO.getKey();
                    exit(0);
                }

                mGame.createNewPiece();
            }
            mTime1 = SDL_GetTicks();
        }
        unsigned long frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - frameTime); // Delay to cap frame rate
        }
    }
    return 0;
}
