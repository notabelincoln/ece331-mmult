// Abe Jordan	2/22/20	mmult.c

/*
 * Multiplies matrix A by matrix B, assumes
 * the number of columns in A matches number
 * of rows in B
 */
int *mmult(int *matrixa, int *matrixb, int a_rows, int a_columns, int b_columns)
{
	int32_t *matrixc;
	int32_t *ptr;
	matrixc = int32_t *calloc(a_rows * b_columns, sizeof(int32_t));
	for (int i = 0; i < a_rows; i++) {
		*matrixc[i] = 
