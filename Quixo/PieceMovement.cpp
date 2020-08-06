#include "PieceMovement.h"

std::string PieceMovement::moveByRules(Board::Position position)
{
	auto[line, column] = position;
	if (column == k_FIRST_COLUMN && line > k_FIRST_LINE && line < k_LAST_LINE)
		return "UDR";
	if (column == k_LAST_COLUMN && line > k_FIRST_LINE && line < k_LAST_LINE)
		return "UDL";
	if (line == k_FIRST_LINE && column > k_FIRST_COLUMN && column < k_LAST_COLUMN)
		return "DLR";
	if (line == k_LAST_LINE && column > k_FIRST_COLUMN && column < k_LAST_COLUMN)
		return "ULR";
	if (line == k_FIRST_LINE && column == k_FIRST_COLUMN)
		return "DR";
	if (line == k_FIRST_LINE && column == k_LAST_COLUMN)
		return "DL";
	if (line == k_LAST_LINE && column == k_FIRST_COLUMN)
		return "UR";
	if (line == k_LAST_LINE && column == k_LAST_COLUMN)
		return "UL";
}

void PieceMovement::moveUpper(Board& board, Board::Position position)
{
	std::cout << "move Upper";
	auto choicenPiece = board[position];
	auto[line, column] = position;
	Piece piece;
	auto tempPieceType = piece.Piece::GetPieceType();
	for (int lineIndex = line; lineIndex > k_FIRST_LINE; --lineIndex)
	{
		std::pair<int, int> tempPosition;
		tempPosition = std::make_pair(lineIndex, column);
		std::pair<int, int> newPosition;
		newPosition = std::make_pair(lineIndex - 1, column);
		std::swap(board[tempPosition], board[newPosition]);
	}
	std::pair<uint8_t, uint8_t> newMovedPosition;
	newMovedPosition.first = k_FIRST_LINE;
	newMovedPosition.second = column;
	std::swap(choicenPiece, board[newMovedPosition]);
}


void PieceMovement::moveDown(Board& board, Board::Position position)
{
	std::cout << "move Down";
	auto choicenPiece = board[position];
	auto[line, column] = position;
	Piece piece;
	auto tempPieceType = piece.Piece::GetPieceType();
	for (int lineIndex = line; lineIndex < k_LAST_LINE; ++lineIndex)
	{
		std::pair<int, int> tempPosition;
		tempPosition = std::make_pair(lineIndex, column);
		std::pair<int, int> newPosition;
		newPosition = std::make_pair(lineIndex + 1, column);
		std::swap(board[tempPosition], board[newPosition]);
	}
	std::pair<uint8_t, uint8_t> newMovedPosition;
	newMovedPosition.first = k_LAST_LINE;
	newMovedPosition.second = column;
	std::swap(choicenPiece, board[newMovedPosition]);
}


void PieceMovement::moveLeft(Board& board, Board::Position position)
{
	std::cout << "move Left";
	auto choicenPiece = board[position];
	auto[line, column] = position;
	Piece piece;
	auto tempPieceType = piece.Piece::GetPieceType();
	for (int columnIndex = column; columnIndex > k_FIRST_COLUMN; --columnIndex)
	{
		std::pair<int, int> tempPosition;
		tempPosition = std::make_pair(line, columnIndex);
		std::pair<int, int> newPosition;
		newPosition = std::make_pair(line, columnIndex - 1);
		std::swap(board[tempPosition], board[newPosition]);
	}
	std::pair<uint8_t, uint8_t> newMovedPosition;
	newMovedPosition.first = line;
	newMovedPosition.second = k_FIRST_COLUMN;
	std::swap(choicenPiece, board[newMovedPosition]);
}


void PieceMovement::moveRight(Board& board, Board::Position position)
{
	std::cout << "move Right";
	auto choicenPiece = board[position];
	auto[line, column] = position;
	Piece piece;
	auto tempPieceType = piece.Piece::GetPieceType();
	for (int columnIndex = column; columnIndex < k_LAST_COLUMN; ++columnIndex)
	{
		std::pair<int, int> tempPosition;
		tempPosition = std::make_pair(line, columnIndex);
		std::pair<int, int> newPosition;
		newPosition = std::make_pair(line, columnIndex + 1);
		std::swap(board[tempPosition], board[newPosition]);
	}
	std::pair<uint8_t, uint8_t> newMovedPosition;
	newMovedPosition.first = line;
	newMovedPosition.second = k_LAST_COLUMN;
	std::swap(choicenPiece, board[newMovedPosition]);
}
