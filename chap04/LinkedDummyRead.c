#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int				data;
	struct _node	*next;
} Node;

int	main(void)
{
	Node	*head = NULL;
	Node	*tail = NULL;
	Node	*cur = NULL;
	Node	*dum = NULL;

	Node	*newNode = NULL;
	int		readData;

	dum = malloc(sizeof(*dum));
	dum->next = NULL;

	head = dum;
	tail = dum;
	while (1)
	{
		printf("Input natural number: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = malloc(sizeof (*newNode));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	printf("Print all datas!\n");
	
	cur = head;
	if (cur->next == NULL)
		printf("There is no data\n");
	while (cur->next != NULL)
	{
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n\n");

	Node	*delNode = head;
	Node	*delNextNode = head->next;

	while(delNextNode != NULL)
	{
		delNode = delNextNode;
		delNextNode = delNextNode->next;

		printf("%d will be deleted\n", delNode->data);
		free(delNode);
	}

	return (0);
}
