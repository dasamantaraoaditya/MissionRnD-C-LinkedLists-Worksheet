#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/numberToLinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(numberToLinkedListSpec)
	{
	public:

		bool compare(int A[], int len, struct node *head) {
			int i = 0;
			for (; i < len && head; ++i) {
				if (A[i] != head->num) {
					return false;
				}
				head = head->next;
			}
			return i == len && !head;
		}

		TEST_METHOD(zeroNumber)
		{
			int num = 0;
			struct node *head = numberToLinkedList(num);
			Assert::IsTrue(head->num == num && !head->next, L"Number zero case failed.", LINE_INFO());
		}

		TEST_METHOD(negativeNumber)
		{
			int num = -4568;
			int A[] = { 4, 5, 6, 8 };
			struct node *head = numberToLinkedList(num);
			Assert::IsTrue(compare(A, 4, head), L"Negative number case failed.", LINE_INFO());
		}

		TEST_METHOD(positiveNumber)
		{
			int num = 8348;
			int A[] = { 8, 3, 4, 8 };
			struct node *head = numberToLinkedList(num);
			Assert::IsTrue(compare(A, 4, head), L"Positive number case failed.", LINE_INFO());
		}

	};
}