#include "stdafx.h"
#include "CppUnitTest.h"
#include <malloc.h>
#include "../src/sortLinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(sortLinkedListSpec)
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

		bool compare(struct node *head, struct node *result) {
			while (head && result && head->num == result->num) {
				head = head->next;
				result = result->next;
			}
			return !head && !result;
		}

		TEST_METHOD(nullCheck)
		{
			Assert::IsNull(sortLinkedList(NULL), L"Null check failed.", LINE_INFO());
		}

		TEST_METHOD(sortedLinkedList)
		{
			struct node *head = createList(1234);
			Assert::IsTrue(compare(sortLinkedList(head), head), L"Sorted Linked list check failed.", LINE_INFO());
		}

		TEST_METHOD(singleNode)
		{
			struct node *head = createList(1);
			Assert::IsTrue(compare(sortLinkedList(head), head), L"Single Node check failed.", LINE_INFO());
		}

		TEST_METHOD(moreThanOneNode)
		{
			struct node *head = createList(42153);
			Assert::IsTrue(compare(sortLinkedList(head), createList(12345)), L"Random Linked list check failed.", LINE_INFO());
		}

	};
}