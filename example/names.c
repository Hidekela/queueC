#include <stdio.h>
#include <string.h>

#define Q_DATA_TYPE char // I will store names
#define Q_DATA_LENGHT 20 // So it's char[20]

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
        printf("%s\n",queue_getFirst(&queueNames));
        queue_pop(&queueNames);
    }

    queue_push(&queueNames,"Saitama");
    printf("%s\n",queue_getFirst(&queueNames));

    queue_push(&queueNames,"Garou");
    queue_push(&queueNames,"King");
    
    queue_quit(&queueNames);
    return 0;
}


// Definition of some functions

bool queue_push(Queue *queue, const char *name)
{
    Q_DATA_TYPE *newName = queue_createData(queue);
    strcpy(newName,name);
    return queue_pushData(queue,newName);
}
