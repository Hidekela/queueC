#include <stdio.h>
#include <string.h>
#include "../queueC.h"

// Prototypes of some functions

bool queue_push(Queue *queue, const char *name);


// Main program

int main()
{
    Queue queueNames;
    queue_init(&queueNames);

    queue_push(&queueNames,"Billi");
    queue_push(&queueNames,"John");
    queue_push(&queueNames,"Jason");

    puts("Let's show names:\n");
    while(!queue_isEmpty(&queueNames))
    {
        printf("%s\n",(char*) queue_getFirst(&queueNames));
        queue_pop(&queueNames);
    }

    queue_push(&queueNames,"Saitama");
    printf("%s\n",(char*) queue_getFirst(&queueNames));

    queue_push(&queueNames,"Garou");
    queue_push(&queueNames,"King");
    
    queue_quit(&queueNames);
    return 0;
}


// Definition of some functions

bool queue_push(Queue *queue, const char *name)
{
    char *newName = (char*) queue_createData(queue,sizeof(char),20); // Name should at most 19 characters here
    strcpy(newName,name);
    return queue_pushData(queue,newName);
}
