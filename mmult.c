// Abe Jordan	2/22/20	mmult.c

/*
 * multiplies matrix a by matrix b to produce matrix c, returns null pointer
 * if the two matrices cannot be multiplied.
 */
struct matrix *mmult(const struct matrix *a, const struct matrix *b)
{
	struct matrix *c;
	// pointers to the elements in matrices a, b, c 
	int32_t *aelmnt, *belmnt, *celmnt;
	
	// checks if matrices have invalid or mismatched dimensions
	if (a->m_rows < 1 || a->n_columns < 1 || b->m_rows < 1 || b->n_columns < 1) {
		printf("ERROR: invalid dimensions\n");
		return 0;
	} else if (a->n_columns != b->m_rows) {
		printf("ERROR: inappropriate dimensions");
		return 0;
	}
	
	// set the correct size parameters for matrix c
	c->m_rows = a->m_rows;
	c->n_columns = b->n_columns;
	
	// create array of pointers for matrix c
	c->array = (int32_t *)calloc(c->m_rows * c->n_columns, sizeof(int32_t));

	// initialize the pointers to the beginning of each matrix
	aelmnt = a->array;
	belmnt = b->array;
	celmnt = c->array;

	// actually produces the multiplied matrix
	for (int i = 0; i < (c->m_rows); i++) {
		for (int j = 0; j < (c->n_columns); j++) {
			for (int k = 0; k < (a->n_columns); k++) {
				// result is the elements in row a times elements in column b
				*celmnt += *(aelmnt + k);
				*celmnt *= *(belmnt + (b->n_columns * k)); 
					*(belmnt +(b->n_columns * k));
			ccol++;
			bcol++;
		}
		arow += (a->n_columns);
	}

}
