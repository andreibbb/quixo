#pragma once
#include "Board.h"
#include "Piece.h"

const int k_FIRST_LINE = 0;
const int k_FIRST_COLUMN = 0;
const int k_LAST_COLUMN = 4;
const int k_LAST_LINE = 4;

class PieceMovement
{
public:
	std::string moveByRules(Board::Position position);
	void moveUpper(Board& board, Board::Position position);
	void moveDown(Board& board, Board::Position position);
	void moveLeft(Board& board, Board::Position position);
	void moveRight(Board& board, Board::Position position);
};

