/**
 * list data structure containing the tasks in the system
 */

#include "task.h"

struct node {
    Task* task;
    struct node* next;
};

// insert and delete operations.
void insert(struct node** head, Task* task);
void delete(struct node** head, Task* task);
void traverse(struct node* head);
void sortBurst(struct node** head);
void sortPriority(struct node** head);

void calculate_waiting_time(double total_wait_time, double total_tasks);
void calculate_turnaround_time(double total_turnaround_time, double total_tasks);
void calculate_response_time(double total_response_time, double total_tasks);
