#pragma once
#include "Board.h"
#include "Piece.h"

const int K_VALID_PIECE_NUMBER = 5;
const int k_VALID_BORDER_PIECE_NUMBER = 20;

class StateChecker
{
public:
	enum class State {
		WinX,
		Win0,
		Draw,
		None
	};
public:
	static State Checker(const Board& board, const Board::Position& position);
};

