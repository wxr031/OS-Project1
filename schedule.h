#ifndef SCHEDULE_H
#define SCHEDULE_H

#define MAX_PROCESS_NUM 4096
#define MAX_PROCESS_NAME_LENGTH 32

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct process {
	char process_name[MAX_PROCESS_NAME_LENGTH];
	uint32_t ready_time;
	uint32_t execution_time;
};

static void die(const char *format, ...) {
    va_list vargs;
    va_start(vargs, format);
    vfprintf(stderr, format, vargs);
    fprintf(stderr, "\n");
    va_end(vargs);
    exit(EXIT_FAILURE);
}

typedef struct process process_t;

#endif
