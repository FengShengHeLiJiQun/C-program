/*******************************************************************************
* Filename:
*	ListReverse
*Description:
*	
*Author:
	QHH
*Time:
	2020.8.1
********************************************************************************/

/*******************************************************************************
* Include
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


//Define a linked list structure.
typedef struct node
{
	int data;
	struct node *next;
}Node;

Node* ReverseK(Node* head, int k);

int main()
{
	Node *head , *p, *q;
	int i, n, a;
	printf("Please enter the number of nodes:\n");
	scanf("%d", &n);
	head = NULL;
	printf("Please enter the node value:\n");
	for (i = 0; i < n; i ++)
	{
		//Apply for a space for the new node dynamically,
		//and point to the new address with the temporary node p
		p = (Node*)malloc(sizeof(Node));
		scanf("%d", &a);
		p -> data = a;
		p -> next = NULL;
		if (head == NULL)
			head = p;
		else
			q  -> next = p;
		q = p;	//Prepare for the next cycle
	}
	
	//Output linked list content.
	printf("The linked list data is :\n");
	Node *temp = head;
	//The output list
	while(temp != NULL)
	{	
		printf("%d\t",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
	
	//Output inverted linked list content.
	head = ReverseK(head, 3);
	printf("The inverted linked list is :\n");
	Node *temp2 = head;
	//The output list
	while(temp2 != NULL)
	{	
		printf("%d\t",temp2 -> data);
		temp2 = temp2 -> next;
	}
	printf("\n");

	return 0;
}



/*******************************************************************************
*****************
* FUNCTION
*	link list reverse
*DESCRIPTION
*	step k
*PARAMETERS
*	head		structure
*	k		step
*RETURNS
*	head
*****************
*******************************************************************************/

Node* ReverseK(Node* head, int k)
{
	Node* pre;
	Node* p = head;
	Node* q = head;
	

	if (!p || k ==1)
		return p;
	for (int i = 1; i < k; i ++)
	{
		//Determine the position of the last node of the linked list in group k
		if(!q -> next && i < 2)
			return head;
		if(!q ->next)	//if node position betwwen 2 and k,continue with subsequent operations.
			continue;
		q = q -> next;
	}

	//reverse
	pre = p;
	head = q;
	while(p -> next != head)
	{
		q = p -> next;
		p -> next = p -> next -> next;
		q -> next = pre;
		pre = q;
	}
	//recursion
	p -> next = ReverseK(head -> next, k);
	head -> next = pre;
	return head;
}
	