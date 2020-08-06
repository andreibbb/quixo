#include "stdafx.h"
#include "CppUnitTest.h"

#include "StateChecker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuixoTests
{
	TEST_CLASS(StateCheckerTests)
	{
	public:

		TEST_METHOD(NoneOnePiece)
		{
			Board board;
			Board::Position lastPosition{ 2, 1 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::None);
		}

		TEST_METHOD(WinLineOne)
		{
			Board board;
			board[{0, 0}] = Piece(Piece::Type::X);
			board[{0, 1}] = Piece(Piece::Type::X);
			board[{0, 2}] = Piece(Piece::Type::X);
			board[{0, 3}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 0, 4 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}

		TEST_METHOD(WinLineTwo)
		{
			Board board;
			board[{1, 0}] = Piece(Piece::Type::X);
			board[{1, 1}] = Piece(Piece::Type::X);
			board[{1, 2}] = Piece(Piece::Type::X);
			board[{1, 3}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 1, 4 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinLineThree)
		{
			Board board;
			board[{2, 0}] = Piece(Piece::Type::X);
			board[{2, 1}] = Piece(Piece::Type::X);
			board[{2, 2}] = Piece(Piece::Type::X);
			board[{2, 3}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 2, 4 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinLineFour)
		{
			Board board;
			board[{3, 0}] = Piece(Piece::Type::X);
			board[{3, 1}] = Piece(Piece::Type::X);
			board[{3, 2}] = Piece(Piece::Type::X);
			board[{3, 3}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 3, 4 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinLineFive)
		{
			Board board;
			board[{4, 0}] = Piece(Piece::Type::X);
			board[{4, 1}] = Piece(Piece::Type::X);
			board[{4, 2}] = Piece(Piece::Type::X);
			board[{4, 3}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 4 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinColumnOne)
		{
			Board board;
			board[{0, 0}] = Piece(Piece::Type::X);
			board[{1, 0}] = Piece(Piece::Type::X);
			board[{2, 0}] = Piece(Piece::Type::X);
			board[{3, 0}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 0 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinColumnTwo)
		{
			Board board;
			board[{0, 1}] = Piece(Piece::Type::X);
			board[{1, 1}] = Piece(Piece::Type::X);
			board[{2, 1}] = Piece(Piece::Type::X);
			board[{3, 1}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 1 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinColumnThree)
		{
			Board board;
			board[{0, 2}] = Piece(Piece::Type::X);
			board[{1, 2}] = Piece(Piece::Type::X);
			board[{2, 2}] = Piece(Piece::Type::X);
			board[{3, 2}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 2 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinColumnFour)
		{
			Board board;
			board[{0, 3}] = Piece(Piece::Type::X);
			board[{1, 3}] = Piece(Piece::Type::X);
			board[{2, 3}] = Piece(Piece::Type::X);
			board[{3, 3}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 3 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinColumnFive)
		{
			Board board;
			board[{0, 4}] = Piece(Piece::Type::X);
			board[{1, 4}] = Piece(Piece::Type::X);
			board[{2, 4}] = Piece(Piece::Type::X);
			board[{3, 4}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 4 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}
		TEST_METHOD(WinMainDiagonal)
		{
			Board board;
			board[{0, 0}] = Piece(Piece::Type::X);
			board[{1, 1}] = Piece(Piece::Type::X);
			board[{2, 2}] = Piece(Piece::Type::X);
			board[{3, 3}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 4 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}

		TEST_METHOD(WinSecondaryDiagonal)
		{
			Board board;
			board[{0, 4}] = Piece(Piece::Type::X);
			board[{1, 3}] = Piece(Piece::Type::X);
			board[{2, 2}] = Piece(Piece::Type::X);
			board[{3, 1}] = Piece(Piece::Type::X);
			Board::Position lastPosition{ 4, 0 };
			board[lastPosition] = Piece(Piece::Type::X);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::WinX);
		}

		TEST_METHOD(WinLineOne0)
		{
			Board board;
			board[{0, 0}] = Piece(Piece::Type::O);
			board[{0, 1}] = Piece(Piece::Type::O);
			board[{0, 2}] = Piece(Piece::Type::O);
			board[{0, 3}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 0, 4 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}

		TEST_METHOD(WinLineTwo0)
		{
			Board board;
			board[{1, 0}] = Piece(Piece::Type::O);
			board[{1, 1}] = Piece(Piece::Type::O);
			board[{1, 2}] = Piece(Piece::Type::O);
			board[{1, 3}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 1, 4 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinLineThree0)
		{
			Board board;
			board[{2, 0}] = Piece(Piece::Type::O);
			board[{2, 1}] = Piece(Piece::Type::O);
			board[{2, 2}] = Piece(Piece::Type::O);
			board[{2, 3}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 2, 4 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinLineFour0)
		{
			Board board;
			board[{3, 0}] = Piece(Piece::Type::O);
			board[{3, 1}] = Piece(Piece::Type::O);
			board[{3, 2}] = Piece(Piece::Type::O);
			board[{3, 3}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 3, 4 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinLineFive0)
		{
			Board board;
			board[{4, 0}] = Piece(Piece::Type::O);
			board[{4, 1}] = Piece(Piece::Type::O);
			board[{4, 2}] = Piece(Piece::Type::O);
			board[{4, 3}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 4 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}

		TEST_METHOD(WinColumnOne0)
		{
			Board board;
			board[{0, 0}] = Piece(Piece::Type::O);
			board[{1, 0}] = Piece(Piece::Type::O);
			board[{2, 0}] = Piece(Piece::Type::O);
			board[{3, 0}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 0 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinColumnTwo0)
		{
			Board board;
			board[{0, 1}] = Piece(Piece::Type::O);
			board[{1, 1}] = Piece(Piece::Type::O);
			board[{2, 1}] = Piece(Piece::Type::O);
			board[{3, 1}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 1 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinColumnThree0)
		{
			Board board;
			board[{0, 2}] = Piece(Piece::Type::O);
			board[{1, 2}] = Piece(Piece::Type::O);
			board[{2, 2}] = Piece(Piece::Type::O);
			board[{3, 2}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 2 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinColumnFour0)
		{
			Board board;
			board[{0, 3}] = Piece(Piece::Type::O);
			board[{1, 3}] = Piece(Piece::Type::O);
			board[{2, 3}] = Piece(Piece::Type::O);
			board[{3, 3}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 3 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinColumnFive0)
		{
			Board board;
			board[{0, 4}] = Piece(Piece::Type::O);
			board[{1, 4}] = Piece(Piece::Type::O);
			board[{2, 4}] = Piece(Piece::Type::O);
			board[{3, 4}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 4 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		TEST_METHOD(WinMainDiagonal0)
		{
			Board board;
			board[{0, 0}] = Piece(Piece::Type::O);
			board[{1, 1}] = Piece(Piece::Type::O);
			board[{2, 2}] = Piece(Piece::Type::O);
			board[{3, 3}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 4 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}

		TEST_METHOD(WinSecondaryDiagonal0)
		{
			Board board;
			board[{0, 4}] = Piece(Piece::Type::O);
			board[{1, 3}] = Piece(Piece::Type::O);
			board[{2, 2}] = Piece(Piece::Type::O);
			board[{3, 1}] = Piece(Piece::Type::O);
			Board::Position lastPosition{ 4, 0 };
			board[lastPosition] = Piece(Piece::Type::O);

			Assert::IsTrue(StateChecker::Checker(board, lastPosition) == StateChecker::State::Win0);
		}
		
	};
}