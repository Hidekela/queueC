/**
 * @file queueC.c
 * @author Hidekela (rhidekela@gmail.com)
 * @brief Queue manager library in C
 * 
 *                                      MIT LICENSE
 *
 *      Permission is hereby granted, free of charge, to any person obtaining a copy
 *      of this software and associated documentation files (the "Software"), to deal
 *      in the Software without restriction, including without limitation the rights
 *      to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *      copies of the Software, and to permit persons to whom the Software is
 *      furnished to do so, subject to the following conditions:
 * 
 *      The above copyright notice and this permission notice shall be included in
 *      all copies or substantial portions of the Software.
 * 
 *      THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *      IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *      FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *      AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *      LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *      OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *      THE SOFTWARE.
 * 
 * 
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "queueC.h"

/**
 * @brief Check the existence of a queue
 * 
 * @param queue the queue
 * @return true if exist
 * @return false 
 */
bool queue_exist(Queue *queue)
{
    return queue != NULL;
}

/**
 * @brief Init the queue
 * 
 * @param queue the queue
 * @return Queue* a pointer to the queue (needed if you want to allocate the queue dynamically,
 *  and if it is, then you must quit the queue by queue_quit() in order to free it in the end)
 */
Queue* queue_init(Queue *queue)
{
    /* Create the queue if it doesn't exist */
    if(!queue_exist(queue))
    {
        queue = malloc(sizeof(*queue));
        if(!queue_exist(queue))
            exit(EXIT_FAILURE);
        queue->isDynamicallyAllocated = true;
    }
    else
        queue->isDynamicallyAllocated = false;

    /* Fill the queue properties */
    queue->current = NULL;
    queue->last = NULL;
    queue->dataManagement = false;

    /* Another properties: length, etc... */

    return queue;
}

/**
 * @brief Check if the queue doesn't contain anything
 * 
 * @param queue the queue
 * @return true if the queue is empty
 * @return false 
 */
bool queue_isEmpty(Queue *queue)
{
    return queue->current == NULL;
}

/**
 * @brief Destroy the queue
 * 
 * @param queue the queue
 * @return Queue* NULL (needed if you allocated dynamically the queue and want
 *  to secure the pointer to the queue)
 */
Queue* queue_quit(Queue *queue)
{
    if(!queue_exist(queue))
        return NULL;

    while (!queue_isEmpty(queue))
    {
        queue_pop(queue);
    }

    if(queue->isDynamicallyAllocated)
    {
        free(queue);
    }
    
    return NULL;
}

/**
 * @brief Delete the first element of the queue. Warning! If you have used queue_createData() and 
 *  the type of your data structure contain dynamically allocated variables, free those variables
 *  before using this function
 * 
 * @param queue the queue
 */
void queue_pop(Queue *queue)
{
    if(!queue_exist(queue))
        return;

    if(queue_isEmpty(queue))
        return;

    Cell *toDelete = queue->current;

    /* Free the data if it should be */
    if(queue->dataManagement)
        free(toDelete->data);

    /* Free the cell */
    queue->current = queue->current->next;
    free(toDelete);

    /* Secure the last cell */
    if(queue->current == NULL)
        queue->last = NULL;
}

/**
 * @brief Add an element in the last of the queue. The data of element must be already
 *  dynamically allocated (by queue_createData() or malloc()) and filled by yourself.
 *  Note that if you don't manage yourself the data allocation and freeing, you must use
 *  queue_createData() in order to tell the library to manage it (allocation and freeing).
 *  You can create a new function of push costumized in your need for creation of data
 *  (allocation), add of the data items (fill properties) and call queue_pushData() in the end.
 * 
 *  For example: 
 *      #define Q_DATA_LENGTH 20
 *      bool queue_push(Queue *queue, int age, const char name) 
 *  where data is an instance of a structure containing 'age' and 'name': 
 *      struct{int age, char name[20]}
 * 
 * @param queue the queue
 * @param data the data of the new element
 * @return true if the operation succeed
 * @return false 
 */
bool queue_pushData(Queue *queue, Q_DATA_TYPE *data)
{
    if(!queue_exist(queue)) // Should be warning
    {
        puts("Error: queue doesn't exist!\n");
        exit(EXIT_FAILURE);
    }

    /* Create a new cell */
    Cell *newCell = malloc(sizeof(Cell));

    /* If the creation of cell fails */
    if(newCell == NULL)
    {
        if(queue->dataManagement)
            free(data);
        return false;
    }

    /* Fill the properties of the cell */
    newCell->data = data;
    newCell->next = NULL;

    if(queue_isEmpty(queue))
        queue->current = newCell;
    else
        queue->last->next = newCell;

    queue->last = newCell;

    return true;
}

/**
 * @brief Allocate (dynamically) memory spaces for a new data. Warning! If you manage yourself the allocation
 *   and freeing of the data, so never use this function for the concerned queue.
 * 
 * @param queue the queue
 * @return Q_DATA_TYPE* pointer of the new data
 */
Q_DATA_TYPE* queue_createData(Queue *queue)
{
    if(!queue->dataManagement)
        queue->dataManagement = true;

    return malloc(sizeof(Q_DATA_TYPE)*Q_DATA_LENGTH);
}

/**
 * @brief Return the first element of the queue
 * 
 * @param queue the queue
 * @return Q_DATA_TYPE* the pointer to the first data
 */
Q_DATA_TYPE* queue_getFirst(Queue *queue)
{
    return queue->current->data;
}
