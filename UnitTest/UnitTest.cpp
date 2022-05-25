#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab12_6.6\main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = nullptr, * last = nullptr;
			enqueue(first, last, 4);
			Assert::AreEqual(search(first, 4), 0);
		}
	};
}
