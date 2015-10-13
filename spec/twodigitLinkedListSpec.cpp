#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/twodigitLinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(twodigitLinkedListSpec)
	{
	public:
		struct node * createNode(int n1, int n2) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->digit1 = n1;
			newNode->digit2 = n2;
			newNode->next = NULL;
			return newNode;
		}

		void add(struct node **head, int p,int q){
			struct node *temp = *head;
			if (*head == NULL){
				(*head) = createNode(p, q);
				(*head)->next = NULL;
			}
			else{
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createNode(p, q);
				temp->next->next = NULL;
			}
		}
		TEST_METHOD(Simple2digit)
		{
			int num = 0;
			struct node *head = NULL;
			add(&head, 1,2);
			add(&head, 5,6);
			add(&head, 3,4);
			num = convert_sll_2digit_to_int(head);
			Assert::IsTrue(num==125634, L"Failed for input 125634.", LINE_INFO());
		}
		TEST_METHOD(Zero2digit)
		{
			int num = 0;
			struct node *head = NULL;
			add(&head, 0, 0);
			num = convert_sll_2digit_to_int(head);
			Assert::IsTrue(num == 0, L"Failed for input 125634.", LINE_INFO());
		}
		TEST_METHOD(Repeated2digit)
		{
			int num = 0;
			struct node *head = NULL;
			add(&head, 1,1);
			add(&head, 2,2);
			add(&head, 3,3);
			num = convert_sll_2digit_to_int(head);
			Assert::IsTrue(num == 112233, L"Failed for input 125634.", LINE_INFO());
		}
		TEST_METHOD(Leadingzero2digit)
		{
			int num = 0;
			struct node *head = NULL;
			add(&head, 0, 0);
			add(&head, 2, 2);
			add(&head, 3, 3);
			num = convert_sll_2digit_to_int(head);
			Assert::IsTrue(num == 2233, L"Failed for input 125634.", LINE_INFO());
		}
	};
}