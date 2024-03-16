/**
 * Various list operations
 */
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"
#include "task.h"


// add a new task to the list of tasks
void insert(struct node** head, Task* newTask) {
    // add the new task to the list 
    struct node* newNode = malloc(sizeof(struct node));

    newNode->task = newTask;
    newNode->next = NULL;

    if (*head != NULL)
    {
        struct node* traverse_list = *head;
        while(traverse_list->next != NULL){
            traverse_list = traverse_list->next;
        }
        traverse_list -> next = newNode;
    }
    else 
    {
        *head = newNode;
    }

}

// delete the selected task from the list
void delete(struct node** head, Task* task) {
    struct node* temp;
    struct node* prev;

    temp = *head;
    // special case - beginning of list
    if (strcmp(task->name,temp->task->name) == 0) {
        *head = (*head)->next;
    }
    else {
        // interior or last element in the list
        prev = *head;
        temp = temp->next;
        while (strcmp(task->name,temp->task->name) != 0) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
    }
}

// traverse the list
void traverse(struct node* head) {
    struct node* temp;
    temp = head;

    while (temp != NULL) {
        printf("[%s] [%d] [%d]\n",temp->task->name, temp->task->priority, temp->task->burst);
        temp = temp->next;
    }
}

void sortBurst(struct node** head)
{
    struct node* current = *head;
    struct node* nextNode = NULL;
    Task* tempTask;

    do {
        nextNode = current->next;

        while (nextNode != NULL) 
        {
            if (current->task->burst > nextNode->task->burst ||
               (current->task->burst == nextNode->task->burst && current->task->tid > nextNode->task->tid)) 
            {
                // Swap tasks if the current task has a larger burst time
                tempTask = current->task;
                current->task = nextNode->task;
                nextNode->task = tempTask;
            }

            nextNode = nextNode->next;
        } 

        current = current->next;
    } while (current != NULL);
}
void sortPriority(struct node** head)
{
    struct node* current = *head;
    struct node* nextNode = NULL;
    Task* tempTask;

    do {
        nextNode = current->next;

        while (nextNode != NULL) 
        {
            if (current->task->priority < nextNode->task->priority ||
               (current->task->priority == nextNode->task->priority && current->task->tid > nextNode->task->tid)) 
            {
                // Swap tasks if the current task has a larger burst time
                tempTask = current->task;
                current->task = nextNode->task;
                nextNode->task = tempTask;
            }

            nextNode = nextNode->next;
        } 

        current = current->next;
    } while (current != NULL);
}

void calculate_waiting_time(double total_wait_time, double total_tasks)
{
    double average_wait_time = 0.0;
    average_wait_time = total_wait_time / total_tasks;
    printf("Average waiting time = %0.2f\n", average_wait_time);
}

void calculate_turnaround_time(double total_turnaround_time, double total_tasks)
{
    double average_turnaround_time = 0.0;
    average_turnaround_time = total_turnaround_time / total_tasks;
    printf("Average turnaround time = %0.2f\n", average_turnaround_time);
}

void calculate_response_time(double total_response_time, double total_tasks)
{
    double average_response_time = 0.0;
    average_response_time = total_response_time / total_tasks;
    printf("Average response time = %0.2f\n", average_response_time);
}
