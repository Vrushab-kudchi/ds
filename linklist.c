/* Write a C program to simulate the working of a singly linked list providing the following operations:
   a. Display & Insert b. Delete from the beginning/end c. Delete a given element */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *link;
};
typedef struct node *NODE;

// Function to obtain a new node from the availability list
NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node)); // try to allocate required size of memory
	if (x == NULL)
	{
		printf("OUT OF MEMORY\n");
		exit(0);
	}
	return x; // allocation successful and return the address
}

// Function to return the allocated memory to availability list
void freenode(NODE x)
{
	free(x);
}

// Function to insert an item at the front end of the list.
NODE insert_front(int item, NODE first)
{
	NODE temp;
	temp = getnode();
	temp->info = item;
	temp->link = first;
	return temp;
}

// Delete a node from the front end
NODE delete_front(NODE first)
{
	NODE temp;
	if (first == NULL)
	{
		printf("List is empty cannot delete\"");
		return first;
	}
	temp = first;
	first = first->link;
	printf("The item deleted is=%d\n", temp->info);
	freenode(temp);
	return first;
}

// Function to delete a node whose info field is specified
NODE delete_info(int item, NODE first)
{
	NODE prev, cur;
	if (first == NULL)
	{
		printf("List is empty");
		return NULL;
	}
	if (item == first->info)
	{
		cur = first; // delete first node
		first = first->link;
		freenode(cur);
		return first;
	}
	// Find a address of the node to be deleted and its predecessor
	prev = NULL;
	cur = first;
	while (cur != NULL && item != cur->info)
	{
		prev = cur;
		cur = cur->link;
	}

	if (cur == NULL) // item not found
	{
		printf("Item not found");
		return first;
	}
	// Establish link between the predessor and successor
	prev->link = cur->link;
	freenode(cur);
	return first;
}

// Display singly linked list
void display(NODE first)
{
	NODE temp;
	if (first == NULL)
	{
		printf("List is emoty");
		return;
	}
	printf("The contents of singly linked list\n");
	temp = first;
	while (temp != NULL)
	{
		printf("%d", temp->info);
		temp = temp->link;
	}
	printf("\n");
}

void main()
{
	NODE first;
	first = NULL;
	int choice, item;

	while (1)
	{
		printf("\n 1.Insert front 2.Delete Front 3. Delete a given node 4.Display 5.Exit\n");
		printf("Enter you choice:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter the item to be inserted:");
			scanf("%d", &item);
			first = insert_front(item, first);
			break;

		case 2:
			first = delete_front(first);
			break;

		case 3:
			printf("\nEnter the item to be deleted:");
			scanf("%d", &item);
			first = delete_info(item, first);
			break;

		case 4:
			display(first);
			break;

		default:
			exit(0);
		}
	}
}
