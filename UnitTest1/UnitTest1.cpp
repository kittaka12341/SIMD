#include "pch.h"
#include "CppUnitTest.h"
#include "Add.h"
#include <immintrin.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1_AddWithC)
		{
			const size_t size = 32 * 62 * 10;
			__declspec(align(32)) uint16_t a[size] = { 0 };
			__declspec(align(32)) uint16_t b[size] = { 0 };
			__declspec(align(32)) uint16_t c[size] = { 0 };
			int i;
			int expectedVal = 3;
			int actualVal = 0;
			for (i = 0; i < size; i++) {
				a[i] = 1;
				b[i] = 2;
			}

			AddC(a, b, c, size);

			for (i = 0; i < size; i++) {
				actualVal = c[i];
				Assert::AreEqual(expectedVal, actualVal);
			}
		}

		TEST_METHOD(TestMethod2_AddWithM256)
		{
			const size_t size = 32 * 62 * 10;
			__declspec(align(32)) uint16_t a[size] = { 0 };
			__declspec(align(32)) uint16_t b[size] = { 0 };
			__declspec(align(32)) uint16_t c[size] = { 0 };
			int i;
			int expectedVal = 3;
			int actualVal = 0;
			for (i = 0; i < size; i++) {
				a[i] = 1;
				b[i] = 2;
			}

			AddWithM256i(a, b, c, size);

			for (i = 0; i < size; i++) {
				actualVal = c[i];
				Assert::AreEqual(expectedVal, actualVal);
			}
		}
	};
}
