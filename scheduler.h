#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX_TASKS 3
#define TICK_MS 500

typedef struct
{
    void (*task_func)(void); // Function pointer for task
    int period_ms;           // Task execution period
    int elapsed_ms;          // Time since last run
} Task;

void scheduler_init(void);
void scheduler_run(void);
void add_task(void (*task_func)(void), int period_ms);

#endif