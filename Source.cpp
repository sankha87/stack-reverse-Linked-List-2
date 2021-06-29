//Reverse Linked List using Stack(Array implementation)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int stack[10];
int top = -1;
void push(int element)	//stack operation
{
	top = top + 1;
	stack[top] = element;
}
void pop()				//stack operation
{
	int element = stack[top];
	top = top - 1;
	//	printf("%d has been deleted \n", element);
}
struct Node
{
	int data;
	struct Node *link;
};
void display(struct Node *head_ref)
{
	struct Node *temp = head_ref;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->link;
	}
}
Node* pushLL(Node *head_ref, int num)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = num;
	new_node->link = head_ref;
	head_ref = new_node;
	return head_ref;
}

void appendLL(Node *head_ref, int num)
{
	if (head_ref == NULL)
	{
		printf("This function cannot be used to add a node to an Empty list \n");
		return;
	}
	struct Node *head_ref2 = head_ref;
	struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = num;
	new_node->link = NULL;
	while (head_ref2->link != NULL)
		head_ref2 = head_ref2->link;
	head_ref2->link = new_node;
}

Node* reverseUsingStack(Node *head_ref)
{
	struct Node *ptr = head_ref, *ptr2 = NULL;
	int temp;
	while (ptr != NULL)
	{
		push(ptr->data);
		ptr = ptr->link;
	}
	while (top != -1)
	{
		temp = stack[top];
		pop();
		if (ptr2 == NULL)
			ptr2 = pushLL(ptr2, temp);
		else
			appendLL(ptr2, temp);
	}

	head_ref = ptr2;
	return head_ref;
}

void main()
{
	struct Node *head = NULL;
	int choice, num;
	while (1)
	{
		printf("\n\n1. Display \n");
		printf("2. Add node to empty list / Add at beginning \n");
		printf("3. Add node at the end \n");
		printf("4. Reverse List \n");
		printf("5. Exit \n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			display(head);
			break;
		case 2:
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			head = pushLL(head, num);
			break;
		case 3:
			printf("Enter the number to be inserted: ");
			scanf("%d", &num);
			appendLL(head, num);
			break;
		case 4:
			head = reverseUsingStack(head);
			break;
		case 5:
			exit(1);
		default: printf("Invalid choice \n\n");
		}
	}
	_getch();
}