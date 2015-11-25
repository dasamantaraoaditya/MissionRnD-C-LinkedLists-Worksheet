/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

void insert_at_end(struct node *inter);
struct node * removeEveryKthNode(struct node *head, int K) {
	int counter = 1;
	struct node *result;
	result = head;
	if (K <= 1 || head == NULL)
		return NULL;

	while (head->next != '\0')
	{
		if ((counter + 1) % K == 0)
		{
			head->next = head->next->next;
		}
		else
			head = head->next;

		counter++;
	}
	return result;
}