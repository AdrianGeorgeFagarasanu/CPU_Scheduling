/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE    100
struct node* taskListHead = NULL;

void add(char* name, int priority, int burst)
{

    //Creating task and assigning attributes of said task//
    //--------------------------------------------------//

    Task* currentTask = ( Task * ) malloc( sizeof( Task ) );

    currentTask -> name = name;

    char* nameNum = name + 1;
    currentTask -> tid = atoi(nameNum);
   
    currentTask -> priority = priority;

    currentTask -> burst = burst;

    currentTask -> burstInitial = burst;

    currentTask -> arrivalTime = 0;

    //--------------------------------------------------//

    //Insert current task into list//
    //--------------------------------------------------//
 
    insert(&taskListHead, currentTask);


    //--------------------------------------------------//
    
}

int main(int argc, char* argv[])
{
    FILE* in;
    char* temp;
    char task[SIZE];

    char* name;
    int priority;
    int burst;

    in = fopen(argv[1],"r");
    
    while (fgets(task,SIZE,in) != NULL) {
        temp = strdup(task);
        name = strsep(&temp,",");
        priority = atoi(strsep(&temp,","));
        burst = atoi(strsep(&temp,","));

        // add the task to the scheduler's list of tasks
        add(name,priority,burst);

        free(temp);
    }

    fclose(in);
 
    // invoke the scheduler
    schedule( taskListHead );

    return 0;
}
