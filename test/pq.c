#include "priority_queue.h"

#include <stdio.h>

int priority(void *a, void *b) {
	int A = (int)a, B = (int)b;
	return (A > B) ? 1 : 0;
}

int main() {
	pq_t *pq = pq_create(priority);	
	pq_push(pq, 1);
	pq_push(pq, 2);
	pq_push(pq, 4);
	pq_push(pq, 7);
	pq_push(pq, 6);
	pq_push(pq, 20);
	pq_push(pq, 6);
	pq_push(pq, 11);
	pq_push(pq, -1);
	pq_push(pq, 9);
	pq_push(pq, 3);
	
	while (!pq_empty(pq)) {
		printf("%d\n", (int)(pq_pop(pq)));
	}
	return 0;
}
