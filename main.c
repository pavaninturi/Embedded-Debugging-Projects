#include "scheduler.h"
#include <stdio.h>

void task_led_blink(void)
{
    printf("Task 1: LED Blink - ON/OFF\n");
}

void task_data_log(void)
{
    printf("Task 2: Logging data packet (MediaTek-inspired debugging)\n");
}

int main(void)
{
    scheduler_init();
    add_task(task_led_blink, 500); // Run every 500ms
    add_task(task_data_log, 1000); // Run every 1000ms

    // Simulate 10 ticks
    for (int i = 0; i < 10; i++)
    {
        printf("Tick %d\n", i);
        scheduler_run();
    }
    return 0;
}