#include "ArrayList.h"

void	ListInit(List *plist)
{
	plist->numOfData = 0;
	plist->curPosition = 0;
}

void	LInsert(List *plist, LData data)
{
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
	plist->curPosition = 0;
	if (plist->numOfData > 0)
	{
		*pdata = (plist->arr)[0];
		return (1);
	}
	return (0);
}

int LNext(List*plist, LData *pdata)
{
	(plist->curPosition)++;
	if (plist->curPosition < plist->numOfData)
	{
		*pdata = (plist->arr)[plist->curPosition];
		return (1);
	}
	return (0);
}

LData	LRemove(List *plist)
{
	LData	temp;
	int		next;

	next = plist->curPosition + 1;
	temp = (plist->arr)[plist->curPosition];
	while (next < plist->numOfData)
	{
		(plist->arr)[next - 1] = (plist->arr)[next];
		next++;
	}
	(plist->numOfData)--;
	(plist->curPosition)--;
	return (temp);
}

int	LCount(List *plist)
{
	return (plist->numOfData);
}
