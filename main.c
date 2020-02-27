// Abe Jordan	2/26/2020	main.c
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "mmult.h"

int main(int argc, char *argv[])
{
	struct matrix *a, *b, *c;
	uint32_t am, an, bm, bn;

	am = atoi(argv[1]);
	an = atoi(argv[2]);
	bm = atoi(argv[3]);
	bn = atoi(argv[4]);

	a = (struct matrix *)malloc(sizeof(struct matrix));
	b = (struct matrix *)malloc(sizeof(struct matrix));
	c = (struct matrix *)malloc(sizeof(struct matrix));

	a->m = am;
	a->n = an;
	b->m = bm;
	b->n = bn;

	a->array = (int32_t *)malloc(am * an * sizeof(int32_t));
	b->array = (int32_t *)malloc(bm * bn * sizeof(int32_t));

	c = mmult(a, b);
	for (int i = 0; i < c->m; i++) {
		for (int j = 0; j < c->n; j++)
			printf("%d, ", *(++(c->array)));
		printf("\n");
	}
}
