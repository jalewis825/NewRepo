#include "pch.h"
#include "CppUnitTest.h"
#include "mathyStuff.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My05feb2025test
{
	TEST_CLASS(My05feb2025test)
	{
	public:
		
		TEST_METHOD(TestAdd1)
		{
			Assert::AreEqual(5, add(2,3));
		}
		TEST_METHOD(TestDouble1)
		{
			//Assert::AreEqual(4, 2 + 3);causes test 2 to fail
			Assert::AreEqual(10, doubleValue(5)); // correction of above
		}
		TEST_METHOD(Fancy1)
		{
			Rectangle r{ 3,4 };
			r.width++;
			Assert::AreEqual(16, r.area());
			Assert::AreEqual(4, r.width);
		}
	};
}
