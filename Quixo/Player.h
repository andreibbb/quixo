#include<string>
#include"Board.h"
#include "PieceMovement.h"

class Player
{
public:
	Player(const std::string& name, const char pieceType);
	Board::Position	ReadAndPlacePiece(std::istream& in, Piece&& piece, Board& board) const;
	void MovePieceByGameRules(Piece& piece, Board& board, Board::Position position) const;
	Piece PickPiece() const;

	friend std::ostream& operator << (std::ostream& os, const Player& player);

	// Getter 
	char GetPieceType();

private:
	std::string m_name;
	char m_pieceType;
};
