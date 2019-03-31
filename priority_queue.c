#include "priority_queue.h"

#include <stdint.h>
#include <stdlib.h>

pq_t *pq_create(int (*priority)(void *, void *)) {
	pq_t *pq = (pq_t *)malloc(sizeof(pq_t));
	if (pq == NULL) {
		//die("Cannot create priority queue: malloc error at %s:%s", __FILE__, __LINE__);
	}
	pq->data = (void **)malloc(sizeof(void *));
	if (pq->data == NULL) {
		//die("Cannot create priority queue: malloc error at %s:%s", __FILE__, __LINE__);
	}
	pq->pq_len = pq->pq_size = 0;
	pq->priority = priority;
	return pq;
}

void pq_push(pq_t *pq, void *data) {
	if (pq->pq_len + 1 >= pq->pq_size) {
		pq->pq_size = pq->pq_size ? pq->pq_size * 2 : 8;
		pq->data = realloc(pq->data, sizeof(void *) * pq->pq_size);
	}

	int i = pq->pq_len;
	int j = (i - 1) / 2;
	while (i > 0 && pq->priority(data, pq->data[j])) {
		pq->data[i] = pq->data[j];
		i = j;
		j = j / 2;
	}
	pq->data[i] = data;
	pq->pq_len++;
}

void *pq_pop(pq_t *pq) {
	if (pq->pq_len == 0) {
		return NULL;
	}
	char *data = pq->data[0];

	pq->data[0] = pq->data[pq->pq_len - 1];
	pq->pq_len--;

	int i = 0, j, k;
	while (i < pq->pq_len) {
		int left = i * 2 + 1;
		int right = i * 2 + 2;
		int highest = i;
		if (left < pq->pq_len && pq->priority(pq->data[left], pq->data[highest])) {
			highest = left;
		}
		if (right < pq->pq_len && pq->priority(pq->data[right], pq->data[highest])) {
			highest = right;
		}
		if (highest != i) {
			void *temp = pq->data[i];
			pq->data[i] = pq->data[highest];
			pq->data[highest] = temp;
			i = highest;
		}
		else break;
	}
	return data;
}

int pq_empty(pq_t *pq) {
	return pq->pq_len == 0;
}
