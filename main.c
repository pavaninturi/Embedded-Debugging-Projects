#include "scheduler.h"
#include <stdio.h>
#include <unistd.h>
void task_led_blink(void)
{
    printf("Task 1: LED Blink - ON/OFF\n");
}

void task_data_log(void)
{
    printf("Task 2: Logging data packet (MediaTek-inspired debugging)\n");
}

void task_packet_track(void)
{
    printf("Task 3 : All the packets at the problematic time was tracked\n");
}
int main(void)
{
    scheduler_init();
    add_task(task_led_blink, 500);     // Run every 500ms
    add_task(task_data_log, 1000);     // Run every 1000ms
    add_task(task_packet_track, 1500); // Run every 1500ms
    // Simulate 10 ticks
    for (int i = 0; i < 10; i++)
    {
        printf("Tick %d (500ms)\n", i);
        sleep(10);
        scheduler_run();
    }
    return 0;
}