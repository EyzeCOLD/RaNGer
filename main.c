#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("ERROR: needs one argument.");
		return (1);
	}
	int arr_siz = atoi(argv[1]);
	if (arr_siz < 1)
	{
		printf("ERROR: atoi doesn't like your input number.");
		return (1);
	}
	srand(getpid());
	int *arr = malloc(sizeof(int) * arr_siz);
	if (!arr)
	{
		printf("ERROR: Congrats! malloc failed!");
		return (1);
	}
	memset(arr, -1, arr_siz);
	int num_candidate;
	int	i = 0;
	while (i < arr_siz)
	{
		int j = 0;
		if (rand() % 2)
			num_candidate = rand() % INT_MAX;
		else
			num_candidate = rand() % (INT_MAX - 1) * -1;
		while (j < i)
		{
			if (arr[j] == num_candidate)
			{
				continue;
			}
			j++;
		}
		printf("%d", num_candidate);
		arr[i] = num_candidate;
		i++;
		if (i < arr_siz)
			printf(", ");
	}
	free(arr);
	return (0);
}
