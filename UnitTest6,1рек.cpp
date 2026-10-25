
#include "pch.h"
#include "CppUnitTest.h"
#include "../6,1рек/6,1рек.cpp"     
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRec
{
    TEST_CLASS(UnitTestRec)
    {
    public:
       
        TEST_METHOD(IsSelected_PositiveNotMultipleOf5_True)
        {
            int a[3] = { 7, 1, 49 };
            Assert::IsTrue(IsSelected(a, 0));
            Assert::IsTrue(IsSelected(a, 1));
            Assert::IsTrue(IsSelected(a, 2));
        }

        TEST_METHOD(IsSelected_MultipleOf5_False)
        {
            int a[3] = { 5, 10, 50 };
            Assert::IsFalse(IsSelected(a, 0));
            Assert::IsFalse(IsSelected(a, 1));
            Assert::IsFalse(IsSelected(a, 2));
        }

        TEST_METHOD(IsSelected_ZeroAndNegative_False)
        {
            int a[3] = { 0, -3, -20 };
            Assert::IsFalse(IsSelected(a, 0));
            Assert::IsFalse(IsSelected(a, 1));
            Assert::IsFalse(IsSelected(a, 2));
        }       

        TEST_METHOD(ZeroSelected_ReplacesOnlySelected)
        {
            int a[20] = { 8, 5, 7, -3, 0, 9, 10, 3, -1, 0, 4, 1, -20, 0, -5, 2, -7, 0, -2, -9 };
            int expected[20] = { 0, 5, 0, -3, 0, 0, 10, 0, -1, 0, 0, 0, -20, 0, -5, 0, -7, 0, -2, -9 };
            ZeroSelected(a, 20, 0);
            for (int i = 0; i < 20; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        
        TEST_METHOD(ZeroSelected_CountAndSumBecomeZero)
        {
            int a[20] = { 8, 5, 7, -3, 0, 9, 10, 3, -1, 0, 4, 1, -20, 0, -5, 2, -7, 0, -2, -9 };
            ZeroSelected(a, 20, 0);
            Assert::AreEqual(0, Count(a, 20, 0));
            Assert::AreEqual(0, Sum(a, 20, 0));
        }

        
        TEST_METHOD(Create_ValuesInRange)
        {
            int a[20];
            for (int k = 0; k < 50; k++)               
            {
                Create(a, 20, -20, 50, 0);
                for (int i = 0; i < 20; i++)
                {
                    Assert::IsTrue(a[i] >= -20);
                    Assert::IsTrue(a[i] <= 50);
                }
            }
        }
    };
}