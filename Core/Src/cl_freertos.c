// Copyright Jim Merkle, 3/7/2024
// File: cl_freertos.c
//
// Command Line Parser functions for FreeRTOS examples
//
// Receive input from command line parser, run function with arguments, return status

#include "cl_freertos.h"
#include "FreeRTOS.h"
#include "task.h"

// pcWriteBuffer - A buffer into which the above mentioned details will be written, in ASCII form.
// This buffer is assumed to be large enough to contain the generated report.
// Approximately 40 bytes per task should be sufficient.
//    Task        RunTime       Percent
//Command Line    205928          44%
//IDLE            255529          55%
//Gen Messages    3               <1%
//Default         1818            <1%
int cl_run_time_stats(void)
{
	char writebuffer[200];
	printf("    Task        RunTime       Percent\n");
	vTaskGetRunTimeStats(writebuffer);
	printf("%s\n",writebuffer);
	return 0;
}


// pcWriteBuffer - A buffer into which the above mentioned details will be written, in ASCII form.
// This buffer is assumed to be large enough to contain the generated report.
// Approximately 40 bytes per task should be sufficient.
//    Task     Status  Priority  Stack  Task#
//Command Line    X       6       351     2
//IDLE            R       0       129     4
//Gen Messages    B       4       151     3
//Default         B       6       56      1
int cl_task_list(void)
{
	char writebuffer[200];
	printf("    Task     Status  Priority  Stack  Task#\n");
	vTaskList(writebuffer);
	printf("%s\n",writebuffer);
	return 0;
}
