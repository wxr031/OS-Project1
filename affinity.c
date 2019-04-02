#define _GNU_SOURCE
#include <sched.h>

int main() {
	/* run on CPU 0 only */
	cpu_set_t mask;
	CPU_ZERO(&mask);
	CPU_SET(0, &mask);

	sched_setaffinity(0, sizeof(mask), &mask); // the first 0 means current process
}
