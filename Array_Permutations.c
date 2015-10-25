#include <stdio.h>
#include <stdlib.h>
#define GNUM 3748
#define ARRAYSIZE 26
void InitializeArray(int *numArray, const int arrayLength)
{
	int i, j;
	for (i = 0; i < arrayLength; i++)
	{
		numArray[i] = i+1;
	}
}

int ShuffleArray(int *numArray, const int arrayLength)
{
	int i, j, temp;
	for (i = arrayLength - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = numArray[j];
		numArray[j] = numArray[i];
		numArray[i] = temp;
	}
}
int main()
{

	int i, numArray[ARRAYSIZE];
	int j;
	srand(GNUM);
	long ran_num = 0;
	printf("Hello my name is Adam Dost and here are my permutations\n\n");
	for (j = 0; j <= 10; j++)
	{
		InitializeArray(numArray, ARRAYSIZE);
		for (i = 0; i < ARRAYSIZE; i++)
		{
			printf("%d ", numArray[i]);
		}
		printf("\n");
		ShuffleArray(numArray, ARRAYSIZE);
		for (i = 0; i < ARRAYSIZE; i++)
		{
			printf("%d ", numArray[i]);
		}
		printf("\n");
	}
	
	getchar();
}
