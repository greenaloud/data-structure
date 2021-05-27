#include <stdio.h>

int BSearch(int arr[], int len, int target)
{	
	int first = 0;
	int last = len - 1;
	int mid;

	while(first <= last)
	{
		mid = (first + last)/2;

		if(arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			last = mid - 1;
		else
			first = mid + 1;
	}
	return -1;
}

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = BSearch(arr, sizeof(arr)/sizeof(int), 7);
	if(idx == -1)
		printf("탐색에 실패하였습니다. \n");
	else
		printf("타켓 저장 인덱스: %d \n", idx);

	idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);
	if(idx == -1)
		printf("탐색에 실패하였습니다. \n");
	else
		printf("타켓 저장 인덱스: %d \n", idx);
}