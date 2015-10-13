#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/removeEveryKthNode.cpp"
#include <malloc.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(removeEveryKthNodeSpec)
	{
	public:

		struct node * createNode(int num) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->num = num;
			newNode->next = NULL;
			return newNode;
		}

		struct node * createList(int num) {
			struct node *head = createNode(num % 10);
			num /= 10;
			while (num) {
				struct node *newNode = createNode(num % 10);
				newNode->next = head;
				head = newNode;
				num /= 10;
			}
			return head;
		}

		bool compare(struct node *result, int num) {
			struct node *head = createList(num);
			while (head && result && head->num == result->num) {
				head = head->next;
				result = result->next;
			}
			return !head && !result;
		}

		TEST_METHOD(nullCheck)
		{
			Assert::IsNull(removeEveryKthNode(NULL, 2), L"Null check failed.", LINE_INFO());
		}

		TEST_METHOD(deleteAllNodes)
		{
			struct node *head = createList(1234);
			Assert::IsNull(removeEveryKthNode(head, 1), L"K value 1 case failed.", LINE_INFO());
		}

		TEST_METHOD(zeroKValue)
		{
			struct node *head = createList(1234);
			Assert::IsNull(removeEveryKthNode(head, 0), L"K value 0 case failed.", LINE_INFO());
		}

		TEST_METHOD(negativeKValue)
		{
			struct node *head = createList(1234);
			Assert::IsNull(removeEveryKthNode(head, -3), L"K value less than zero case failed.", LINE_INFO());
		}

		TEST_METHOD(positiveKValue)
		{
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 3), 124578), L"K value odd case failed.", LINE_INFO());
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 2), 1357), L"K value even case failed.", LINE_INFO());
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 8), 1234567), L"K value equal to length case failed.", LINE_INFO());
			Assert::IsTrue(compare(removeEveryKthNode(createList(12345678), 9), 12345678), L"K value greater than length case failed.", LINE_INFO());
		}

	};
}