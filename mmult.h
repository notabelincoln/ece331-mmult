// Abe Jordan	2/26/20	mmult.h
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#ifndef MMULT_H
#define MMULT_H
struct matrix {
	// m_rows and n_columns are size parameters of the matrix
	uint32_t m_rows;
	uint32_t n_columns;
	// *row and *column are pointers to an individual row and column
	uint32_t *row;
	uint32_t *column;
}
// multiplies two matricies a and b and returns a pointer to new matrix c
struct matrix *mmult(const struct matrix *a, const struct matrix *b);
#endif



