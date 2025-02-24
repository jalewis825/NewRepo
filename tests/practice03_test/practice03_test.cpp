#include "pch.h"
#include "CppUnitTest.h"
#include "practice03.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace practice03test
{
    TEST_CLASS(practice03test)
    {
    public:

        TEST_METHOD(TestSumRange)
        {
            // Tests the sum of 1-5 = 10
            int result1 = MathUtils::sumRange(1, 5);
            Assert::AreEqual(15, result1);

            // Test when values are the same, so range = 0
            int result2 = MathUtils::sumRange(0, 0);
            Assert::AreEqual(0, result2);
        }

        TEST_METHOD(TestContainsNegative)
        {
            // Test with no negative values
            std::vector<int> values1{ 3, 1, 5, 7 };
            Assert::IsFalse(MathUtils::containsNegative(values1));

            // Test with negative values
            std::vector<int> values2{ 3, -1, 5, 7 };
            Assert::IsTrue(MathUtils::containsNegative(values2));

            // Test with an empty vector
            std::vector<int> values3{};
            Assert::IsFalse(MathUtils::containsNegative(values3));
        }

        TEST_METHOD(TestFindMax)
        {
            // Standard case with multiple ints and returning max value
            std::vector<int> values1 = { 3, 1, 5, 7 };
            int result = MathUtils::findMax(values1);
            Assert::AreEqual(7, result);

            // Test if all values entered into vector are equal
            std::vector<int> values2 = { 3, 3, 3, 3 };
            result = MathUtils::findMax(values2);
            Assert::AreEqual(3, result);

            // Empty vector (edge case)
            std::vector<int> values3 = {};
            result = MathUtils::findMax(values3);
            Assert::AreEqual(0, result);  // Edge case: Empty vector returns 0
        }
    };
}

//AI: used to help me with the Assert::propeties like AreEquals/IsTrue and to help me with the empty vector on the last test.