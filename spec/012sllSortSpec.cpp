#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/012sllSort.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace spec
{
	TEST_CLASS(w012sllSortSpec)
	{
	public:
		struct node * createNode(int n1) {
			struct node *newNode = (struct node *)malloc(sizeof(struct node));
			newNode->data= n1;
			newNode->next = NULL;
			return newNode;
		}

		void add(struct node **head, int p){
			struct node *temp = *head;
			if (*head == NULL){
				(*head) = createNode(p);
				(*head)->next = NULL;
			}
			else{
				while (temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createNode(p);
				temp->next->next = NULL;
			}
		}

		int check(int *nums, int len, struct node *head){
			int index = 0;
			struct node *temp = head;
			for (index = 0; index < len; index++){
				if (temp-> data != nums[index]){
					return  0;
				}
				temp = temp->next;
			}
			return 1;
		}
		TEST_METHOD(Simple012)
		{
			int num = 0;
			struct node *head = NULL;
			int num_array[100] = {0,0,0,1,1,1,2,2,2,2};
			int output[100] = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 2 };
			int len = 10;
			int i = 0;
			for (i = 0; i<10; i++)
			{
				add(&head, num_array[i]);
			}
			sll_012_sort(head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 0001112222.", LINE_INFO());
		}
		TEST_METHOD(Allzero012)
		{
			int num = 0;
			struct node *head = NULL;
			int num_array[100] = { 0, 0, 0,0,0,0,0,0,0,0 };
			int output[100] = { 0, 0, 0, 0,0,0,0,0,0,0};
			int len = 10;
			int i = 0;
			for (i = 0; i<10; i++)
			{
				add(&head, num_array[i]);
			}
			sll_012_sort(head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 0001112222.", LINE_INFO());
		}
		TEST_METHOD(Reverse012)
		{
			int num = 0;
			struct node *head = NULL;
			int num_array[100] = { 2,2,2,1,1,1,0,0,0};
			int output[100] = { 0,0,0,1,1,1,2,2,2 };
			int len = 9;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				add(&head, num_array[i]);
			}
			sll_012_sort(head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 0001112222.", LINE_INFO());
		}
		TEST_METHOD(Random012)
		{
			int num = 0;
			struct node *head = NULL;
			int num_array[100] = {1,2,1,1,1,2,2,0,0,0,2,1};
			int output[100] = { 0, 0, 0,1,1,1,1,1,2,2,2,2};
			int len = 12;
			int i = 0;
			for (i = 0; i<len; i++)
			{
				add(&head, num_array[i]);
			}
			sll_012_sort(head);
			int d = check(output, len, head);
			Assert::IsTrue(d == 1, L"Failed for sll 0001112222.", LINE_INFO());
		}
	};
}