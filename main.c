#include "schedule.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	
	/* innformation of processes*/
	process_t processes[MAX_PROCESS_NUM];
	
	/*
	 * type of priority, include:
	 *    1. FIFO (First-in First-out)
	 *    2. RR (Round-Robin)
	 *    3. SJF (Fhortest Job First)
	 *    4. PSJF (Preemptive Shortest Job First)
	 */
	char priority_type[8];

	/* number of tasks */
	int task_num;

	if (fgets(priority_type, 8, stdin) == NULL) {
		die("Incorrect input format: %s", "priority_type");
	}
	if (scanf("%d", &task_num) != 1) {
		die("Incorrect input format: %s", "tast_num");
	}
	for (int i = 0; i < task_num; i++) {
		get_process_data(&processes[i]);
	}
	return 0;
}
