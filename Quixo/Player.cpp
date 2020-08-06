#include "Player.h"
#include <fstream>

Player::Player(const std::string& name, const char pieceType) :
	m_name(name),
	m_pieceType(pieceType)
{
	// Empty
}


Board::Position Player::ReadAndPlacePiece(std::istream & in, Piece&& piece, Board& board) const
{
	uint16_t line = UINT16_MAX;
	uint16_t column = UINT16_MAX;

	if (in >> line)
		if (in >> column)
		{
			if (line != k_FIRST_LINE && line != k_LAST_LINE)
				if (column != k_FIRST_COLUMN && column != k_LAST_COLUMN)
				{
					throw "Invalid position, position must be on the border of board. Enter a new position: ";
				}

			Board::Position position = { static_cast<uint8_t>(line), static_cast<uint8_t>(column) };

			auto& optionalPiece = board[position];

			if (optionalPiece)
			{
				throw "That position is occupied by another piece.";
			}

			optionalPiece = std::move(piece);
			while (true)
			{
				try {
					MovePieceByGameRules(piece, board, position);
					break;
				}
				catch (const char* errorMessage)
				{
					std::cout << errorMessage << std::endl;
				}
			}
			return position;

		}

	in.clear();
	in.seekg(std::ios::end);
	throw "Invalid position, enter only numbers. Enter a new position: ";
}

void Player::MovePieceByGameRules(Piece& otherPiece, Board& board, Board::Position position) const
{
	PieceMovement movement;
	std::cout << std::endl;
	std::cout << "Now the board looks like this:\n";
	std::cout << board << std::endl;
	std::string tempMoveRules = movement.moveByRules(position);
	std::cout << "Now you should move piece in one of the following places: ";
	std::cout << tempMoveRules;
	std::cout << ", so enter choicen place." << std::endl;
	std::cout << "(upper=U, down=D, left=L, right=R)" << std::endl;
	char choicenPlace;
	std::cin >> choicenPlace;
	system("cls");
	bool checker = false;
	for (int index = 0; index < tempMoveRules.size(); ++index)
	{
		if (choicenPlace == tempMoveRules[index])
		{
			checker = true;
			break;
		}
	}
	if (checker == true)
	{
		if (choicenPlace == 'U')
			movement.moveUpper(board, position);
		if (choicenPlace == 'D')
			movement.moveDown(board, position);
		if (choicenPlace == 'L')
			movement.moveLeft(board, position);
		if (choicenPlace == 'R')
			movement.moveRight(board, position);
	}
	else
	{
		throw "Invalid place to move. Try again!";
	}
}


Piece Player::PickPiece() const
{
	auto pickedPiece = static_cast<Piece::Type>(m_pieceType);
	return pickedPiece;
}

char Player::GetPieceType()
{
	return m_pieceType;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	return os << player.m_name;
}
