#include "pch.h"
#include "CppUnitTest.h"
#include "../Project4/funkcje.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestyIO
{
	TEST_CLASS(TestyIO)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(4.04305, Logarytm(57));
		}
	};
}