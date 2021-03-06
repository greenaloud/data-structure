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

	Node	*newNode = NULL;
	int		readData;

	while (1)
	{
		printf("Input natural number: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		newNode = malloc(sizeof (*newNode));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	printf("Print all datas!\n");
	if (head == NULL)
		printf("There is no data.\n");
	else
	{
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL)
		return (0);
	else
	{
		Node	*delNode = head;
		Node	*delNextNode = head->next;

		printf("%d will be deleted\n", head->data);
		free(delNode);

		while(delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d will be deleted\n", delNode->data);
			free(delNode);
		}
	}

	return (0);
}
