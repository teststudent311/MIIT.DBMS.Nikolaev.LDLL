#include "pch.h"
#include "CppUnitTest.h"
#include "..\MyList\MyList.cpp"
#include "..\MyList\Element.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyListTests
{
	TEST_CLASS(MyListTests)
	{
	public:
		
		TEST_METHOD(ADD_HEAD_SUCCSESS)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;

			// Act
			List my_list;
			my_list.AddHead(value_1);
			my_list.AddHead(value_2);
			int expected = my_list.head->data;


			// Assert
			Assert::AreEqual(value_2, expected);
		}

		TEST_METHOD(ADD_TAIL_SUCCSESS)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;

			// Act
			List my_list;
			my_list.AddTail(value_1);
			my_list.AddTail(value_2);
			int expected = my_list.tail->data;


			// Assert
			Assert::AreEqual(value_2, expected);
		}

		TEST_METHOD(GetCount_SUCCSESS)
		{
			// Arrange
			const int value = 1;

			// Act
			List my_list;
			my_list.AddHead(value);
			my_list.AddHead(value);
			size_t expected = 2;


			// Assert
			Assert::AreEqual(my_list.GetCount(), expected);
		}

		TEST_METHOD(Contains_ValidData_SUCCSESS)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;

			// Act
			List my_list;
			my_list.AddHead(value_1);


			// Assert
			Assert::IsTrue(my_list.Contains(value_1));
			Assert::IsFalse(my_list.Contains(value_2));
		}

		TEST_METHOD(PrintAll_SUCCSESS)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;

			// Act
			List my_list;
			my_list.AddHead(value_1);
			my_list.AddHead(value_2);
			string expected = "2, 1, ";
			string real = my_list.PrintAll();


			// Assert
			Assert::AreEqual(expected, real);
		}

		TEST_METHOD(Insert_SUCCSESS)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;
			int valueToInsert = 10;
			size_t indexToInsert = 0;

			// Act
			List my_list;
			my_list.AddHead(value_1);
			my_list.AddHead(value_2);
			my_list.Insert(valueToInsert, indexToInsert);
			int expected = my_list.head->data;
			

			// Assert
			Assert::AreEqual(expected, valueToInsert);
		}

		TEST_METHOD(Delete_ValidData_SUCCSESS)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;
			const size_t indexToDelete = 1;

			// Act
			List my_list;
			my_list.AddHead(value_1);
			my_list.AddHead(value_2);
			my_list.Delete(indexToDelete);


			// Assert
			Assert::AreEqual(value_1, my_list.head->data);
		}

		TEST_METHOD(Delete_InvalidData_Failure)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;
			const size_t indexToDelete = 30;
			List my_list;
			my_list.AddHead(value_1);
			my_list.AddHead(value_2);


			// Act & Assert
			Assert::ExpectException<std::out_of_range>([&]() { my_list.Delete(indexToDelete); });
		}

		TEST_METHOD(CopyCtor_ValidData_Success)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;
			List my_list;
			my_list.AddHead(value_1);
			my_list.AddHead(value_2);

			// Act
			List new_list = my_list;

			// Act & Assert
			Assert::AreEqual(my_list.head->data, new_list.head->data);
		}

		TEST_METHOD(MoveCtor_ValidData_Success)
		{
			// Arrange
			const int value_1 = 1;
			const int value_2 = 2;
			List my_list;
			my_list.AddHead(value_1);
			my_list.AddHead(value_2);
			int expected = my_list.head->data;
			Element* expectedPointer = nullptr;

			// Act
			List new_list = move(my_list);

			// Act & Assert
			Assert::AreEqual(expected, new_list.head->data);
			//Assert::AreEqual(my_list.head, expectedPointer);
		}

	};
}
