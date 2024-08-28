#ifndef _PIECE_
#define _PIECE_

class Piece
{
public:
    int getBlockType(int pPiece, int pRotation, int pX, int pY);
    int getXInitialPosition(int pPiece, int pRotation);
    int getYInitialPosition(int pPiece, int pRotation);

private:
    char mPieces[7][4][5][5];
    int mPiecesInitialPosition[7 /*kind */][4 /* r2otation */][2 /* position */];
};

int Piece::getBlockType(int pPiece, int pRotation, int pX, int pY)
{
    return mPieces[pPiece][pRotation][pX][pY];
}

// returns the horizontal displacement
int Piece::getXInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][0];
}
// returns the vertical displacement
int Piece::getYInitialPosition(int pPiece, int pRotation)
{
    return mPiecesInitialPosition[pPiece][pRotation][1];
}

#endif // _PIECE_