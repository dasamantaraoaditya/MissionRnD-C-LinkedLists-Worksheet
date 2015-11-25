/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};
void sll_012_sort(struct node *head){
	int count0 = 0, count1 = 0, count2 = 0;
	struct node *inter;
	inter = head;
	while (head != '\0')
	{
		if (head->data == 1)
			count1++;
		else if (head->data == 0)
			count0++;
		else
			count2++;
		head = head->next;
	}


	while (count0--)
	{
		inter->data = 0;
		inter = inter->next;
	}
	while (count1--)
	{
		inter->data = 1;
		inter = inter->next;
	}
	while (count2--)
	{
		inter->data = 2;
		inter = inter->next;
	}
}