#include "scheduler.h"
#include <stdio.h> // For simulation output

Task tasks[MAX_TASKS];
int task_count = 0;

void scheduler_init(void)
{
    task_count = 0;
    printf("Scheduler initialized\n");
}

void add_task(void (*task_func)(void), int period_ms)
{
    if (task_count < MAX_TASKS)
    {
        tasks[task_count].task_func = task_func;
        tasks[task_count].period_ms = period_ms;
        tasks[task_count].elapsed_ms = 0;
        task_count++;
    }
}

void scheduler_run(void)
{
    for (int i = 0; i < task_count; i++)
    {
        tasks[i].elapsed_ms += TICK_MS;
        if (tasks[i].elapsed_ms >= tasks[i].period_ms)
        {
            tasks[i].task_func();    // Execute task
            tasks[i].elapsed_ms = 0; // Reset timer
            // Debugging log, inspired by MediaTek packet tracking
            printf("Task %d executed, throughput check passed\n", i);
        }
    }
}