// Abe Jordan	2/26/2020	main.c
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "mmult.h"

int main(int argc, char *argv[])
{
	// Declare pointers to matrices and time-keeping variables
	struct matrix *a, *b, *c;
	struct timespec begin, end;
	uint32_t delta_time;
	// Used to easily store values in matrices
	int32_t *ptrA, *ptrB, *ptrC;

	// Allocate space for each of the matrices
	a = (struct matrix *)malloc(sizeof(struct matrix));
	b = (struct matrix *)malloc(sizeof(struct matrix));
	c = (struct matrix *)malloc(sizeof(struct matrix));

	// Set the dimensions of the two multiplied matrices
	a->m = atoi(argv[1]);
	a->n = atoi(argv[2]);
	b->m = atoi(argv[3]);
	b->n = atoi(argv[4]);

	// Create pointers to matrix a and matrix b
	a->array = (int32_t *)calloc(a->m * a->n, sizeof(int32_t));
	b->array = (int32_t *)calloc(b->m * b->n, sizeof(int32_t));
	
	ptrA = a->array;
	ptrB = b->array;

	// Prints array a
	printf("MATRIX A:\n");
	for (int i = 0; i < a->m; i++) {
		for (int j = 0; j < a->n; j++) {
			*ptrA = (rand() % 3);
			printf("%d, ", *ptrA);
			ptrA++;
		}
		printf("\n");
	}

	// Prints array b
	printf("MATRIX B:\n");
	for (int i = 0; i < b->m; i++) {
		for (int j = 0; j < b->n; j++) {
			*ptrB = (rand() % 3);
			printf("%d, ", *ptrB);
			ptrB++;
		}
		printf("\n");
	}

	// Timing block for the function
	clock_gettime(CLOCK_REALTIME, &begin);
	c = mmult(a, b);
	clock_gettime(CLOCK_REALTIME, &end);

	if (c == 0)
		return 1;

	ptrC = c->array;
	
	// Prints array c
	
	printf("MATRIX C:\n");
	for (int i = 0; i < c->m; i++) {
		for (int j = 0; j < c->n; j++) {
			printf("%d, ", *ptrC);
			ptrC++;
		}
		printf("\n");
	}
	delta_time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);

	printf("TIME TO MULTIPLY MATRIX: %d\n", delta_time);
	return 0;
}
