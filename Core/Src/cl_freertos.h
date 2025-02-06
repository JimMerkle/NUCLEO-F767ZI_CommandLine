// Copyright Jim Merkle, 3/7/2024
// File: cl_freertos.h
//
// Provide defines, prototypes, enumerations for cl_freertos.c functions

#ifndef _cl_freertos_h_
#define _cl_freertos_h_

#include "command_line.h"
#include "FreeRTOS.h"
#include "task.h"

// Prototypes
int cl_run_time_stats(void);
int cl_task_list(void);

// Command Line functions for command table
#define FREERTOS_COMMANDS \
{"osinfo",    "Show FreeRTOS task info",                      1, cl_run_time_stats}, \
{"oslist",    "Show FreeRTOS task list",                      1, cl_task_list}


#endif // _cl_freertos_h_
