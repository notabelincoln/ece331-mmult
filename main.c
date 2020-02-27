// Abe Jordan	2/26/2020	main.c
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "mmult.h"

int main(int argc, char *argv[])
{
	// declare pointers to matrices and time-keeping variables
	struct matrix *a, *b, *c;
	struct timespec begin, end;
	uint32_t delta_time;

	// allocate space for each of the matrices
	a = (struct matrix *)malloc(sizeof(struct matrix));
	b = (struct matrix *)malloc(sizeof(struct matrix));
	c = (struct matrix *)malloc(sizeof(struct matrix));

	// set the dimensions of the two multiplied matrices
	a->m = atoi(argv[1]);
	a->n = atoi(argv[2]);
	b->m = atoi(argv[3]);
	b->n = atoi(argv[4]);

	// create pointers to matrix a and matrix b
	a->array = (int32_t *)malloc(a->m * a->n * sizeof(int32_t));
	b->array = (int32_t *)malloc(b->m * b->n * sizeof(int32_t));
	
	for (int i = 0; i < a->m; i++) {
		for (int j = 0; j < a->n; j++) {
			*(++(a->array)) = j;
			printf("%d, ", *(a->array));
		}
		printf("\n");
	}

	for (int i = 0; i < b->m; i++) {
		for (int j = 0; j < b->n; j++) {
			*(++(b->array)) = i;
			printf("%d, ", *(b->array));
		}
		printf("\n");
	}

	c = mmult(a, b);

	if (c == 0)
		return 1;

	clock_gettime(CLOCK_REALTIME, &begin);
	for (int i = 0; i < c->m; i++) {
		for (int j = 0; j < c->n; j++)
			printf("%d, ", *(++(c->array)));
		printf("\n");
	}
	clock_gettime(CLOCK_REALTIME, &end);
	delta_time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);

	printf("TIME TO MULTIPLY MATRIX: %d\n", delta_time);
	return 0;
}
