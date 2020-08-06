#include <stdio.h>
#include <stdlib.h>

//Define a linked list structure.
typedef struct node
{
	int data;
	struct node* next;
}Node;
void insert(Node **head, int value);
int main()
{
	Node *head;
	head = NULL;
	int n;	//create n nodes
	printf("Please enter the number of nodes: \n");
	scanf("%d", &n);
	printf("Please enter the  nodes value: \n");
	for (int i = 0; i < n; ++i)
	{
		int a ;	//The value assigned to node.
		scanf("%d", &a);
		insert(&head, a);
	}
	printf("The linked list data is :\n");
	Node *temp = head;

	//The output list
	while(temp != NULL)
	{	
		printf("%d\t",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
	return 0;
}

//Function to add a linked list node
//Head insertion sort
void insert(Node **head, int value)
{	//The address of the header node
	Node *temp = (Node*)malloc(sizeof(Node));
	temp -> next = NULL;
	temp -> data = value;
	if ((*head) == NULL)
	{
		(*head) = temp;
	}
	else
	{
		 Node *t = (*head);

		if(temp->data < (*head) ->data)
		 {
			temp->next = (*head);
			(*head) = temp;
            			return;
        		}
        		while(t != NULL)
		 {
           			if(t->next == NULL)  
			{
                			t->next = temp;
               				return;
            			 }
		 	else if(t->next->data > temp->data)
			 {
               				temp->next = t->next;
               				t->next = temp;
                			return;
            			 }
           		 	t = t->next;
       	 	}

    	}
}
		

