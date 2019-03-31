#include "schedule.h"

#include <stdio.h>

void get_process_data(process_t *process) {
	if (fgets(process->process_name, MAX_PROCESS_NAME_LENGTH, stdin) == NULL) {
		die("Incorrect input format: %s", "process_name");
	}
	if (scanf("%d", &(process->ready_time)) != 1) {
		die("Incorrect input format: %s", "ready_time");
	}
	if (scanf("%d", &(process->execution_time)) != 1) {
		die("Incorrect input format: %s", "execution_time");
	}
}
