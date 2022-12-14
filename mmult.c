// Abe Jordan	2/22/20	mmult.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mmult.h"
/*
 * Multiplies matrix a by matrix b to produce matrix c, returns null pointer
 * if the two matrices cannot be multiplied.
 */
struct matrix *mmult(const struct matrix *a, const struct matrix *b)
{
	// Pointer to resulting matrix
	struct matrix *c;
	// Pointers to the elements in matrices a, b, c 
	int32_t *arow, *bcol, *celmnt;
	
	// Checks if matrices have invalid or mismatched dimensions
	if (a->m < 1 || a->n < 1 || b->m < 1 || b->n < 1) {
		printf("ERROR: invalid dimensions\n");
		return 0;
	} else if (a->n != b->m) {
		printf("ERROR: inappropriate dimensions\n");
		return 0;
	}
	
	c = (struct matrix *)malloc(sizeof(struct matrix));

	// Set the correct size parameters for matrix c
	c->m = a->m;
	c->n = b->n;
	
	// Create array of pointers for matrix c
	c->array = (int32_t *)calloc(c->m * c->n, sizeof(int32_t));

	// Initialize the pointers to the beginning of each matrix
	arow = a->array;
	bcol = b->array;
	celmnt = c->array;

	// Actually produces the multiplied matrix
	for (int i = 0; i < (c->m); i++) {
		for (int j = 0; j < (c->n); j++) {
			for (int k = 0; k < (a->n); k++)
				*celmnt += *(arow + k) * *(bcol + b->n * k);
			celmnt++;
			bcol++;
		}
		// Reset bcol to top row of matrix
		bcol = b->array;

		arow += (a->n);
	}

	return c;
}
