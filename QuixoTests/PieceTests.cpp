#include "stdafx.h"
#include "CppUnitTest.h"

#include "Piece.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuixoTests
{
	TEST_CLASS(PieceTests)
	{
	public:

		TEST_METHOD(DefaultConstructor)
		{
			Piece piece(Piece::Type::X);
			Assert::IsTrue(Piece::Type::X == piece.GetPieceType());
		}

		TEST_METHOD(EmptyConstructor)
		{
			Piece piece(Piece::Type::None);
			Assert::IsTrue(Piece::Type::None == piece.GetPieceType());
		}

		TEST_METHOD(CharConstructor)
		{
			Piece piece('X');
			Assert::IsTrue(Piece::Type::X == piece.GetPieceType());
		}


		TEST_METHOD(CopyConstructor)
		{
			Piece piece(Piece::Type::X);
			Piece tempPiece(piece);
			Assert::IsTrue(piece == tempPiece);
		}

	};
}