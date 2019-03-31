#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdint.h>
#include <stdlib.h>

struct pq {
    void **data;
    uint32_t pq_len, pq_size;
	int (*priority)(void *, void *);
};

typedef struct pq pq_t;

pq_t *pq_create(int (*)(void *, void *));
int pq_empty(pq_t *pq);
void pq_push(pq_t *, void *);
void *pq_pop(pq_t *);

#endif
