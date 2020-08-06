#include "StateChecker.h"

StateChecker::State StateChecker::Checker(const Board& board, const Board::Position & position)
{
	auto[line, column] = position;
	int numberOfX;
	int numberOf0;
	bool find5X = false;
	bool find50 = false;
	Piece piece;
	for (int lineIndex = 0; lineIndex < Board::kHeight; ++lineIndex)
	{
		numberOf0 = 0;
		numberOfX = 0;
		for (int columnIndex = 0; columnIndex < Board::kWidth; ++columnIndex)
		{
			std::pair<int, int> currentPosition;
			currentPosition = std::make_pair(lineIndex, columnIndex);
			piece = *board[currentPosition];
			auto pieceType = piece.Piece::GetPieceType();
			if (!find5X && pieceType == Piece::Type::X)
				numberOfX++;
			else
				if (!find50 && pieceType == Piece::Type::O)
					numberOf0++;
		}
		if (numberOfX == K_VALID_PIECE_NUMBER)
			find5X = true;

		else
			if (numberOf0 == K_VALID_PIECE_NUMBER)
				find50 = true;
	}
	if (!find50 || !find5X)
		for (int columnIndex = 0; columnIndex < Board::kWidth; ++columnIndex)
		{
			numberOf0 = 0;
			numberOfX = 0;
			for (int lineIndex = 0; lineIndex < Board::kHeight; ++lineIndex)
			{
				std::pair<int, int> currentPosition;
				currentPosition = std::make_pair(lineIndex, columnIndex);
				piece = *board[currentPosition];
				auto pieceType = piece.Piece::GetPieceType();
				if (!find5X &&pieceType == Piece::Type::X)
					numberOfX++;
				else
					if (!find50 &&pieceType == Piece::Type::O)
						numberOf0++;
			}
			if (numberOfX == K_VALID_PIECE_NUMBER)
				find5X = true;

			else
				if (numberOf0 == K_VALID_PIECE_NUMBER)
					find50 = true;
		}
	if (!find50 || !find5X)
	{
		numberOf0 = 0;
		numberOfX = 0;
		for (int lineIndex = 0; lineIndex < Board::kHeight; ++lineIndex)
		{

			for (int columnIndex = 0; columnIndex < Board::kWidth; ++columnIndex)
			{
				if (columnIndex == lineIndex)
				{
					std::pair<int, int> currentPosition;
					currentPosition = std::make_pair(lineIndex, columnIndex);
					piece = *board[currentPosition];
					auto pieceType = piece.Piece::GetPieceType();
					if (!find5X &&pieceType == Piece::Type::X)
						numberOfX++;
					else
						if (!find50 &&pieceType == Piece::Type::O)
							numberOf0++;
				}
			}
			if (numberOfX == K_VALID_PIECE_NUMBER)
				find5X = true;

			else
				if (numberOf0 == K_VALID_PIECE_NUMBER)
					find50 = true;
		}
	}
	if (!find50 || !find5X)
	{
		numberOf0 = 0;
		numberOfX = 0;

		for (int lineIndex = 0; lineIndex < Board::kHeight; ++lineIndex)
		{
			for (int columnIndex = 0; columnIndex < Board::kWidth; ++columnIndex)
			{
				if ((columnIndex + lineIndex) == (Board::kWidth - 1))
				{
					std::pair<int, int> currentPosition;
					currentPosition = std::make_pair(lineIndex, columnIndex);
					piece = *board[currentPosition];
					auto pieceType = piece.Piece::GetPieceType();
					if (!find5X &&pieceType == Piece::Type::X)
						numberOfX++;
					else
						if (!find50 &&pieceType == Piece::Type::O)
							numberOf0++;
				}
			}
			if (numberOfX == K_VALID_PIECE_NUMBER)
				find5X = true;

			else
				if (numberOf0 == K_VALID_PIECE_NUMBER)
					find50 = true;
		}
	}
	if (find50&&find5X)
		return State::Draw;
	else
		if (find50)
			return State::Win0;
		else
			if (find5X)
				return State::WinX;
			else
				if (board.IsFull() == true)
					return State::Draw;

	int numberOfPieces = 0;
	for (int columnIndex = 0; columnIndex < Board::kWidth; ++columnIndex)
	{
		std::pair<int, int> currentPosition;
		currentPosition = std::make_pair(0, columnIndex);
		piece = *board[currentPosition];
		auto pieceType = piece.Piece::GetPieceType();
		if (pieceType == Piece::Type::X || pieceType == Piece::Type::O)
			numberOfPieces++;
		currentPosition = std::make_pair(Board::kWidth - 1, columnIndex);
		piece = *board[currentPosition];
		pieceType = piece.Piece::GetPieceType();
		if (pieceType == Piece::Type::X || pieceType == Piece::Type::O)
			numberOfPieces++;
	}
	for (int lineIndex = 0; lineIndex < Board::kWidth; ++lineIndex)
	{
		std::pair<int, int> currentPosition;
		currentPosition = std::make_pair(lineIndex, 0);
		piece = *board[currentPosition];
		auto pieceType = piece.Piece::GetPieceType();
		if (pieceType == Piece::Type::X || pieceType == Piece::Type::O)
			numberOfPieces++;
		currentPosition = std::make_pair(lineIndex, Board::kWidth - 1);
		piece = *board[currentPosition];
		pieceType = piece.Piece::GetPieceType();
		if (pieceType == Piece::Type::X || pieceType == Piece::Type::O)
			numberOfPieces++;
	}
	if (numberOfPieces == k_VALID_BORDER_PIECE_NUMBER)
		return State::Draw;

	return State::None;
}