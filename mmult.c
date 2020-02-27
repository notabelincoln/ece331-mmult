// Abe Jordan	2/22/20	mmult.c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct matrix {
	uint32_t m, n;
	int32_t *array;
};
/*
 * Multiplies matrix a by matrix b to produce matrix c, returns null pointer
 * if the two matrices cannot be multiplied.
 */
struct matrix *mmult(struct matrix *a, struct matrix *b)
{
	// Pointer to new matrix
	struct matrix *c = (struct matrix *)malloc(sizeof(struct matrix));
	// Pointers to the elements in matrices a, b, c 
	int32_t *arow, *bcol, *celmnt;
	
	// Checks if matrices have invalid or mismatched dimensions
	if (a->m < 1 || a->n < 1 || b->m < 1 || b->n < 1) {
		printf("ERROR: invalid dimensions\n");
		return 0;
	} else if (a->n != b->m) {
		printf("ERROR: inappropriate dimensions");
		return 0;
	}
	
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
				*celmnt += *(arow + k) * *(bcol + (b->n * k));
			celmnt++;
			bcol++;
		}
		// Reset bcol to top row of matrix
		bcol = b->array;

		arow += (a->n);
	}

	return c;
}
