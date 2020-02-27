// Abe Jordan	2/22/20	mmult.c

// multiplies matrix A (am x ambn) by matrix B (anbm x bn)
struct matrix *mmult(const struct matrix *a, const struct matrix *b)
{
	// initialize matrix c to NULL pointer so it does not point to garbage
	struct matrix *c = NULL;
	// set the correct size parameters for matrix c
	c->m_rows = a->m_rows;
	c->n_columns = b->n_columns;
	// create array of pointers for matrix c
	c->row = calloc(c->m_rows, sizeof(int32_t));
	// creates a set of columns for each row
	for (int i = 0; i < (c->m_rows); i++)
		(c->row + i) = calloc(c->n_columns, sizeof(int32_t));

}
