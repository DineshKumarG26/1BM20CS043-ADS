
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Node
{
	int data;
	struct Node* npx; 
};

struct Node* XOR (struct Node *a, struct Node *b)
{
	return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}


void insert(struct Node **head_ref, int data)
{

	struct Node *new_node = (struct Node *) malloc (sizeof (struct Node) );
	new_node->data = data;
	
	new_node->npx = *head_ref;

	if (*head_ref != NULL)
	{
	
		(*head_ref)->npx = XOR(new_node, (*head_ref)->npx);
	}

	*head_ref = new_node;
}

void printList (struct Node *head)
{
	struct Node *curr = head;
	struct Node *prev = NULL;
	struct Node *next;

	printf ("Following are the nodes of Linked List: \n");

	while (curr != NULL)
	{
		// print current node
		printf ("%d ", curr->data);
		next = XOR (prev, curr->npx);
		prev = curr;
		curr = next;
	}
}


int main ()
{
    int a[10],n,i;
     struct Node* head = NULL;
    printf("Enter the size: ");
    scanf("%d",&n);
    printf("\n Enter the data: ");
    for( i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        insert(&head,a[i]);
    }
    
    
	printList (head);

	return (0);
}
