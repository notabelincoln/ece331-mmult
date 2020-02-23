#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int main()
{
	int matA[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	int matB[3][3] = {{10,11,12},{13,14,15},{16,17,18}};

	for (int *ptr = matA; ptr != 0; ptr++)
		printf("%d\n", *ptr);
}
