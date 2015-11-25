/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * reverse_linkedlist(struct node *start);
void insert_at_end(struct node *end, int n);
struct node * numberToLinkedList(int N) {
	struct node *head = NULL, *end = NULL, *start = NULL;
	if (N<0)
		N *= -1;
	end = (struct node *)malloc(sizeof(struct node));
	head = end;
	start = end;
	end->num = N % 10;
	end->next = NULL;
	N /= 10;
	while (N)
	{
		insert_at_end(end, N % 10);
		N /= 10;
	}
	head = reverse_linkedlist(start);
	return head;
}

void insert_at_end(struct node *end, int n)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->num = n;
	temp->next = NULL;
	while (end->next != NULL)
		end = end->next;
	end->next = temp;
}

struct node * reverse_linkedlist(struct node *start)
{
	struct node *previous = NULL;
	while (start) {
		struct node *temp = start;
		start = start->next;
		temp->next = previous;
		previous = temp;
	}
	return previous;
}