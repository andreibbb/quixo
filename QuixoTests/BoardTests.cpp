#include "stdafx.h"
#include "CppUnitTest.h"

#include "Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuixoTests
{
	TEST_CLASS(BoardTests)
	{
	public:

		TEST_METHOD(DefaultConstructorEmptyBoard)
		{
			Board board;
			Board::Position position;
			auto&[i, j] = position;
			for (i = 0; i < Board::kHeight; ++i)
				for (j = 0; j < Board::kWidth; ++j)
					if (board[position].has_value())
						Assert::Fail();
		}


		TEST_METHOD(SetGetAtOneOne)
		{
			Board board;
			Piece piece;
			Board::Position position{ 1, 1 };
			board[position] = piece;

			Assert::IsTrue(board[position].has_value());

			Assert::IsTrue(board[position]->GetPieceType() == piece.GetPieceType());

		}

		TEST_METHOD(GetAtOneOneConst)
		{
			const Board board;
			Board::Position position{ 1, 1 };

			Assert::IsFalse(board[position].has_value());
		}

		TEST_METHOD(GetAtMinusOneOneConst)
		{
			const Board board;
			Board::Position position{ -1, 1 };

			Assert::ExpectException<std::out_of_range>([&]() {
				board[position];
			});
		}

		TEST_METHOD(GetAtOneMinusOneConst)
		{
			const Board board;
			Board::Position position{ 1, -1 };

			Assert::ExpectException<std::out_of_range>([&]() {
				board[position];
			});
		}

	
	};
}