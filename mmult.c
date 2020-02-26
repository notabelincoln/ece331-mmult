// Abe Jordan	2/22/20	mmult.c

// Multiplies matrix A (am x ambn) by matrix B (anbm x bn)
struct matrix *mmult(const int32_t *a, const int32_t *b, const uint32_t am,
				 const uint32_t anbm, const uint32_t bn)
{
	int32_t *matrixc, *ptra0,*ptrb0;
	matrixc = int32_t *calloc(ar * bc, sizeof(int32_t));
	for (int32_t i = 0; i < a_rows; i++) {
		for (int32_t j = 0; j < ac; j++)
			matrixc[i][j] = component_result(&a[i][0], &b[0][j], am, bn);
	}
}
