#include "QuixoGame.h"
#include "Board.h"
#include "Piece.h"
#include "Player.h"
#include "StateChecker.h"
#include "PieceMovement.h"
#include <fstream>
#include <iostream>

void QuixoGame::RunGame()
{
	Board board;
	std::string playerName;

	std::cout << "Player 1 (X) Name: ";
	std::cin >> playerName;
	Player firstPlayer(playerName, 'X');
	std::reference_wrapper<Player> placingPlayer = firstPlayer;

	std::cout << "Player 2 (0) Name: ";
	std::cin >> playerName;
	Player secondPlayer(playerName, 'O');
	std::reference_wrapper<Player> waitingPlayer = secondPlayer;

	Board::Position position;
	while (true)
	{
		system("cls");

		std::cout << "The board looks like this:\n";
		std::cout << board << std::endl;

		Piece pickedPiece(placingPlayer.get().GetPieceType());

		std::cout << placingPlayer << ", you should choose position of the piece" << std::endl;

		Board::Position placedPosition;
		while (true)
		{
			try
			{
				placedPosition = placingPlayer.get().ReadAndPlacePiece(std::cin, std::move(pickedPiece), board);
				break;
			}
			catch (const char* errorMessage)
			{
				std::cout << errorMessage << std::endl;
			}
		}

		StateChecker stateChecker;
		auto gameResult = stateChecker.Checker(board, position);
		// break when we have a winner
		if (gameResult == StateChecker::State::WinX) {
			system("cls");
			std::cout << "The board looks like this:\n";
			std::cout << board << std::endl;
			std::cout << "The Winner is: " << placingPlayer << std::endl;
			break;
		}

		// break when we have a draw
		if (gameResult == StateChecker::State::Draw) {
			system("cls");
			std::cout << "The board looks like this:\n";
			std::cout << board << std::endl;
			break;
		}

		if (gameResult == StateChecker::State::Win0) {
			system("cls");
			std::cout << "The board looks like this:\n";
			std::cout << board << std::endl;
			std::cout << "The Winner is: " << waitingPlayer << std::endl;
			break;
		}

		std::swap(placingPlayer, waitingPlayer);
	}
}