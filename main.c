#include "schedule.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

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
	char priority_type[8] = {0};

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
		processes[i].id = i;
	}

	int process_order_len = 0;
	int *process_order = NULL;

	/* decide which scheduling algorithm to use */
	if (!strcmp(priority_type, "FIFO")) {
		process_order = /* TODO */
	}
	else if (!strcmp(priority_type, "RR")) {
		process_order = /* TODO */
	}
	else if (!strcmp(priority_type, "SJF")) {
		process_order = /* TODO */
	}
	else if (!strcmp(priority_type, "PSJF")) {
		process_order = /* TODO */
	}
	else {
		die("Invalid priority type %s", prioity_type);
	}

	pid_t pids[MAX_PROCESS_NUM] = {0};
	struct sigaction act[MAX_PROCESS_NUM] = {0};

	for (int i = 0; i < task_num; i++) {
		act[i].sa_handler = sigusr1_handler;
		act[i].sa_flags = 0;
		sigfillset(&act[i].sa_mask); /* Block every signal during the handler */
		sigaction(SIGUSR1, &act[i], NULL);
	}

	/* simulate process scheduling */
	int next_process_id;
	for (int i = 0; i < process_order_len; i++) {
		next_process_id = process_order[i];
		if (pids[next_process_id] == 0) {
			pids[next_process_id] = fork();
			if (pids[next_process_id] == -1) {
				die("Error forking child");
			}
			else if (pids[next_process_id] == 0) { /* child */
				sigsuspend(&act[i].sa_mask);
			}
		}
		kill(pids[next_process_id], SIGUSR1);
		if () { /* if the process terminates */
			kill(pids[next_process_id], SIGUSR2);
		}
	}
	
	return 0;
}
