#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "cpu.h"
#include "list.h"
#include "schedulers.h"



void schedule(struct node *head){

    struct node* current = head;

    double current_time = 0.0;
    double wait_time = 0.0;
    double total_wait_time = 0.0;
    double turnaround_time = 0.0;
    double total_turnaround_time = 0.0;
    double response_time = 0.0;
    double total_response_time = 0.0;
    double total_tasks = 0.0;

    sortBurst(&head);

    while (current != NULL) {
        
        Task* task = current->task;
        total_tasks += 1.0;

        response_time = current_time;
        total_response_time += response_time;

        wait_time = current_time;
        total_wait_time += wait_time;

        run(task, task->burst);

        turnaround_time = current_time + task->burst;
        total_turnaround_time += turnaround_time;

        current = current->next;
        current_time = turnaround_time;


    }
    printf("\n");
    calculate_waiting_time(total_wait_time, total_tasks);
    calculate_turnaround_time(total_turnaround_time, total_tasks);
    calculate_response_time(total_response_time, total_tasks);

}