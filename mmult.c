// Abe Jordan	2/22/20	mmult.c

// Multiplies matrix A (am x ambn) by matrix B (anbm x bn)
int32_t *mmult(const int32_t *a, const int32_t *b, const uint32_t am,
				 const uint32_t anbm, const uint32_t bn)
{
	int32_t *matrixc, *ptra0,*ptrb0;
	matrixc = int32_t *calloc(ar * bc, sizeof(int32_t));
	for (int32_t i = 0; i < a_rows; i++) {
		for (int32_t j = 0; j < ac; j++)
			matrixc[i][j] = component_result(&a[i][0], &b[0][j], am, bn);
	}
}

/*
 * Carries out multiplication of correct values of matrix, requires the number
 * of elements being multiplied from each matrix and the number of columns to
 * count in matrix b.  Pointer arithmetic required to m
 */
int32_t component_result(const int32_t *arow, const int32_t *bcol,
			 const uint32_t num_vals, const uint32_t num_b_cols)
{
	// return value
	int32_t value;

	// pointers to row and column to prevent 
	int32_t *ptrrow, *ptrcol;	
	
	value = 0;			
	ptrrow = arow;
	ptrcol = bcol;

	for (int k = 0; k < num; k++)
		value += *(ptrrow + k) + *(ptrcol + (k * num_b_cols));
	return value;
}
