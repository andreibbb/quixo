#pragma once
#include <iostream>

class Piece
{
public:
	enum class Type : char
	{
		O = 'O',
		X = 'X',
		None
	};

public:
	Piece();
	Piece(Type type);
	Piece(char type);
	Piece(const Piece& other);
	Piece(Piece && other);

	~Piece();

	Piece & operator = (const Piece& other);
	Piece & operator = (Piece && other);
	friend bool operator == (const Piece& first, const Piece& second);

	friend std::ostream& operator << (std::ostream& os, const Piece& piece);

	// getter
	Type GetPieceType();

private:
	Type m_type;
};
