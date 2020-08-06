#include "Board.h"

const std::optional<Piece>& Board::operator[](const Position& position) const
{
	const auto&[line, column] = position;

	if (line >= kHeight || column >= kWidth)
		throw std::out_of_range("Board index out of bound.");

	return m_pieces[line * kWidth + column];
}

std::optional<Piece>& Board::operator[](const Position& position)
{
	const auto&[line, column] = position;

	if (line >= kHeight || column >= kWidth)
		throw std::out_of_range("Board index out of bound.");

	return m_pieces[line * kWidth + column];
}

bool Board::IsFull() const
{
	return std::all_of(
		m_pieces.begin(),
		m_pieces.end(),
		[](const std::optional<Piece>& optionalPiece)
	{
		return optionalPiece.has_value();
	}
	);
}

std::ostream & operator<<(std::ostream & os, const Board & board)
{
	Board::Position position;
	auto&[line, column] = position;

	for (line = 0; line < Board::kHeight; ++line)
	{
		for (column = 0; column < Board::kWidth; ++column)
		{
		
			if (board[position])
				os << *board[position];
			else
				os << kEmptyBoardCell;
			os << ' ';
		
		}
		os << std::endl;
	}

	return os;
}



