#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

int	compare_precede(LData d1, LData d2)
{
	if (d1->xpos == d2->xpos)
	{
		if (d1->ypos < d2->ypos)
			return (0);
	}
	else if (d1->xpos < d2->xpos)
		return (0);
	return (1);
}

int	main(void)
{
	List	list;
	Point	compPos;
	Point	*ppos;

	ListInit(&list);
	SetSortRule(&list, compare_precede);

	ppos = malloc(sizeof(*ppos));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = malloc(sizeof(*ppos));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = malloc(sizeof(*ppos));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = malloc(sizeof(*ppos));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	printf("Number of datas: %d\n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	compPos.xpos = 2;
	compPos.ypos = 0;

	if (LFirst(&list, &ppos))
	{
		if (PointComp(ppos, &compPos) == 1)
		{
			ppos = LRemove(&list);
			free(ppos);
		}

		while (LNext(&list, &ppos))
		{
			if (PointComp(ppos, &compPos) == 1)
			{
				ppos = LRemove(&list);
				free(ppos);
			}
		}
	}

	printf("Number of datas: %d\n", LCount(&list));

	if (LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);

		while (LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return (0);
}
