#include <stdio.h>

int LSearch(int arr[], int len, int target)
{	
	int i;
	for (i=0; i<len; i++)
	{
		if(arr[i] == target)
			return i;
	}
	return -1;
}

int main(void)
{
	int arr[] = {3, 5, 2, 4, 9};

	int idx;

	idx = LSearch(arr, sizeof(arr)/sizeof(int), 4);
	if(idx == -1)
		printf("탐색에 실패했습니다.\n");
	else
		printf("타겟이 저장된 인덱스: %d \n", idx);

	idx = LSearch(arr, sizeof(arr)/sizeof(int), 7);
	if(idx == -1)
		printf("탐색에 실패했습니다.\n");
	else
		printf("타겟이 저장된 인덱스: %d \n", idx);

	return 0;

}