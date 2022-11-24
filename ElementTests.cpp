#include "pch.h"
#include "CppUnitTest.h"
#include "..\MyList\Element.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ElementTests
{
	TEST_CLASS(ElementTests)
	{
	public:
		
		TEST_METHOD(Ctor_Test)
		{
			// Arrange
			const int my_value = 10000;

			// Act
			Element my_element(my_value);

			// Assert
			Assert::AreEqual(my_element.GetData(), my_value);
		}
	};
}
