#include "Piece.h"

Piece::Piece() :
	Piece(Type::None)
{
	// empty
}

Piece::Piece(Type type) :
	m_type(type)
{
	// Empty
	static_assert(sizeof(*this) <= 1, "This class should be 1 byte in size");
}

Piece::Piece(char type)
{
	m_type = static_cast<Type>(type);
}


Piece::~Piece()
{
	m_type = Piece::Type::None;
}

Piece & Piece::operator=(const Piece & other)
{
	m_type = other.m_type;
	return *this;
}

Piece & Piece::operator=(Piece && other)
{
	m_type = other.m_type;
	new(&other) Piece;
	return *this;
}

Piece::Piece(const Piece & other)
{
	*this = other;
}

Piece::Piece(Piece && other)
{
	*this = std::move(other);
}

Piece::Type Piece::GetPieceType()
{
	return m_type;
}

bool operator==(const Piece & first, const Piece & second)
{
	if (first.m_type == second.m_type)
		return true;
	else return false;

}

std::ostream & operator<<(std::ostream & os, const Piece & piece)
{
	return os << static_cast<char>(piece.m_type);
}