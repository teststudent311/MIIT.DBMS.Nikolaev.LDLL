#include "pch.h"
#include "CppUnitTest.h"
#include "..\MyList\Element.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ElementTests
{
	TEST_CLASS(ElementTests)
	{
	public:
		
		TEST_METHOD(Ctor_Success)
		{
			// Arrange
			const int my_value = 10000;

			// Act
			Element my_element(my_value);

			// Assert
			Assert::AreEqual(my_element.data, my_value);
		}
	};
}
