#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "task.h"
#include "cpu.h"
#include "list.h"
#include "schedulers.h"


void schedule(struct node *head){
    struct node* traverse_list  =  head;
    double current_time = 0.0;
    double total_wait_time = 0.0;
    double turnaround_time = 0.0;
    double total_turnaround_time = 0.0;
    double response_time = 0.0;
    double total_response_time = 0.0;
    double total_tasks = 0.0;


    while(traverse_list != NULL){

        total_tasks += 1.0;

        response_time = current_time;
        total_response_time += response_time;

        total_wait_time += current_time;

        run(traverse_list -> task, traverse_list -> task -> burst);

        turnaround_time = current_time + traverse_list -> task-> burst;
        total_turnaround_time += turnaround_time;

        traverse_list = traverse_list -> next;
        current_time = turnaround_time;
       
    }
    printf("\n");
    calculate_waiting_time(total_wait_time, total_tasks);
    calculate_turnaround_time(total_turnaround_time, total_tasks);
    calculate_response_time(total_response_time, total_tasks);

}