#define QUANTUM 10

#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"
#include "cpu.h"

Task* pickNextTask(struct node** head) {
    if (*head == NULL)
        return NULL;

    Task* nextTask = (*head)->task;
    delete(head, nextTask);
    return nextTask;
}

void schedule(struct node* head) {
    double current_time = 0.0;
    //double wait_time = 0.0;
    double total_wait_time = 0.0;
    //double turnaround_time = 0.0;
    double total_turnaround_time = 0.0;
    //double response_time = 0.0;
    double total_response_time = 0.0;
    double total_tasks = 0.0;
    int tasksDone = 0;
    int tasksCounted = 0;

    while (1)
    {
        tasksDone = 1;
        struct node* current = head;

        while (current != NULL ) 
        {

            if (!tasksCounted)
            {
                total_tasks += 1.0;
            }

            while (current->task->burst == 0)
            {

                double turnaround_time = current_time + current->task->burst;
                total_turnaround_time += turnaround_time;

                struct node* temp = current;
                current = current->next;
                delete(&head, temp->task);
                free(temp);

                if (current == NULL)
                {
                    break;
                }
            }

            if (current == NULL)
            {
                break;
            }

            Task* task = current->task;

            if (task->burst > 0)
            {
                tasksDone = 0;
            }

            double wait_time = current_time;
            total_wait_time += wait_time;

            if (!tasksCounted)
            {
                double response_time = current_time;
                total_response_time += response_time;
                
                task->arrivalTime = current_time;
            }
            

            int time_slice = (task->burst > QUANTUM) ? QUANTUM : task->burst;

            run(task, time_slice);

            task->burst -= time_slice;

            current_time += time_slice;

            
            current = current->next;
            

        }

        tasksCounted = 1;

        if (tasksDone)
        {
            break;
        }

    }

    printf("\n");
    calculate_waiting_time(total_wait_time, total_tasks);
    calculate_turnaround_time(total_turnaround_time, total_tasks);
    calculate_response_time(total_response_time, total_tasks);
}
