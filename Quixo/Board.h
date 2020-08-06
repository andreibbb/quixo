#pragma once

#include<array>
#include<optional>
#include"Piece.h"

const char kEmptyBoardCell[] = "_";

class Board
{
public:
	using Position = std::pair<uint8_t, uint8_t>;
public:
	Board()=default;
	friend std::ostream& operator << (std::ostream& os, const Board& board);
	// Getter
	const std::optional<Piece>& operator[] (const Position& pos) const;
	// Getter and/or Setter
	std::optional<Piece>& operator[] (const Position& pos);

	bool IsFull() const;

	static const size_t kWidth = 5;
	static const size_t kHeight = 5;
private:
	static const size_t kSize = kWidth * kHeight;

private:
	std::array<std::optional<Piece>, kSize> m_pieces;
	
};

