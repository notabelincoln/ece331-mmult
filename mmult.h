// Abe Jordan	2/26/20	mmult.h
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#ifndef MMULT_H
#define MMULT_H
struct matrix {
	// m number of rows, n number of columns
	uint32_t m;
	uint32_t n;
	int32_t *array;
};
// multiplies two matricies a and b and returns a pointer to new matrix c
struct matrix *mmult(const struct matrix *a, const struct matrix *b);
#endif
