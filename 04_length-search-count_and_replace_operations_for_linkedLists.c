
#include	<stdio.h>
#include	<stdlib.h>
#include	<stdbool.h>

typedef struct	node
{
	int			value;
	struct node	*next;
}	Node;

void	printList(Node	*head);
Node	*insertAtHead(Node	*head, int newValue);
Node	*insertAtTail(Node 	*head, int newValue);
Node	*deleteAtHead(Node	*head);
Node	*deleteAtTail(Node 	*head);
int		length(Node	*head);		// Find the LENGTH of a Linked List
int		recursiveLength(Node	*node);		// Find the LENGTH of a Linked List recursively
bool	isMember(Node	*node, int findValue);	// SEARCH for a MEMBER in a Linked List
int		countMatches(Node	*node, int findValue);	// Find & COUNT Matches in a Linked List
void	replaceMatches(Node	*node, int findValue, int replaceValue);	// Find & REPLACE Matches in a Linked List;

int	main()
{
	Node	*myListHead;

	myListHead = NULL;

	myListHead = insertAtHead(myListHead, 7);
	myListHead = insertAtHead(myListHead, 5);
	myListHead = insertAtHead(myListHead, 3);
	myListHead = insertAtTail(myListHead, 5);
	myListHead = insertAtTail(myListHead, 10);
	myListHead = insertAtTail(myListHead, 10);
	myListHead = insertAtTail(myListHead, 12);
	myListHead = insertAtTail(myListHead, 14);

	printf("\nLinked List LENGTH: %d\n", length(myListHead));	// LENGTH

	printf("COUNT: Number of 5s: %d\n", countMatches(myListHead, 5));			// Find & COUNT Matches
	printf("COUNT: Number of 10s: %d\n", countMatches(myListHead, 10));		// Find & COUNT Matches;
	printf("COUNT: Number of 12s: %d\n", countMatches(myListHead, 12));		// Find & COUNT Matches;
	printf("COUNT: Number of 8s: %d\n", countMatches(myListHead, 8));			// Find & COUNT Matches;

	printf("\nList before REPLACEMENT...\n");
	printList(myListHead);
	replaceMatches(myListHead, 5, 9);	// Find and REPLACE Matches in a Linked List
	replaceMatches(myListHead, 14, 11);	// Find and REPLACE Matches in a Linked List
	printf("\nList after REPLACEMENT...\n");
	printList(myListHead);

	printf("\nBefore DELETE at HEAD and TAIL...\n");
	printList(myListHead);

	myListHead = deleteAtHead(myListHead);
	myListHead = deleteAtHead(myListHead);
	printf("\nAfter DELETE at HEAD...\n");
	printList(myListHead);
	printf("Linked List LENGTH Recursive: %d\n", recursiveLength(myListHead));	// Recursive LENGTH

	if (isMember(myListHead, 7))	// SEARCH list MEMBER
		printf("SEARCH: 7 is in the list!\n");
	else
		printf("SEARCH: 7 is not in the list!\n");

	if (isMember(myListHead, 8))	// SEARCH list MEMBER
		printf("SEARCH: 8 is in the list!\n");
	else
		printf("SEARCH: 8 is not in the list!\n");

	myListHead = deleteAtTail(myListHead);
	myListHead = deleteAtTail(myListHead);
	printf("\nAfter DELETE at TAIL...\n");
	printList(myListHead);
	printf("Linked List LENGTH: %d\n\n", length(myListHead));	// LENGTH

	return (0);
}

int	length(Node	*head)	//== Find the LENGTH of a Linked List
{
	Node	*current;
	current = head;
	int		length = 0;

	while (current != NULL)
	{
		length++;
		current = current->next;
	}

	return (length);
}

int	recursiveLength(Node	*node)	//== Find the LENGTH of a Linked List recursively
{
	if (node == NULL)
		return (0);
	else
		return (1 + recursiveLength(node->next));
}

bool	isMember(Node	*node, int findValue)	//== SEARCH for a MEMBER in a Linked List
{
	if (node == NULL)
		return (false);
	else if (node->value == findValue)
		return (true);
	else
		return (isMember(node->next, findValue));
}

int	countMatches(Node	*node, int findValue)	//== Find and COUNT Matches in a Linked List
{
	if (node == NULL)
		return (0);
	else if (node->value == findValue)
		return (1 + isMember(node->next, findValue));
	else
		return (countMatches(node->next, findValue));
}

void	replaceMatches(Node	*node, int findValue, int replaceValue)	//== Find & REPLACE Matches in a Linked List;
{
	if (node != NULL)
	{
		if (node->value == findValue)
			node->value = replaceValue;

		replaceMatches(node->next, findValue, replaceValue);
	}
}

Node	*insertAtHead(Node 	*head, int newValue)
{
	Node	*newNode = calloc(1, sizeof(Node));
	newNode->value = newValue;

	if (head == NULL)
		return (newNode);
	else
	{
		newNode->next = head;
		return (newNode);
	}
			// OR //
	// if (head != NULL)
	// {
	// 	newNode->next = head;
	// 	return (newNode);
	// }
	
	// return (newNode);
}

Node	*insertAtTail(Node 	*head, int newValue)
{
	Node	*newNode = calloc(1, sizeof(Node));
	newNode->value = newValue;

	if (head == NULL)
		return (newNode);
	else
	{
		Node	*current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = newNode;
		return (head);
	}
}

Node	*deleteAtHead(Node	*head)
{
	if (head == NULL)
		return (NULL);
	else
	{
		Node	*toReturn = head->next;
		free (head);
		return (toReturn);
	}
}

Node	*deleteAtTail(Node	*head)
{
	if (head == NULL)
		return (NULL);
	else if (head->next == NULL)
	{
		free (head);
		return (NULL);
	}
	else
	{
		Node	*current = head;
		Node	*previous = NULL;

		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}

		previous->next = NULL;
		free (current);
		return (head);
	}
}

void	printList(Node	*head)
{
	Node	*current;
	current = head;
	int		i = 0;

	while (current != NULL)
	{
		printf("Node %d: %d\n", i, current->value);
		i++;
		current = current->next;
	}
}
