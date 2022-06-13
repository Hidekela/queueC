/**
 * @file queueC.h
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
 * @version 1.0
 * @date 2022-06-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdbool.h>

typedef struct _Queue_Cell Queue_Cell;
struct _Queue_Cell
{
    void *data;
    Queue_Cell *next;
};

typedef struct _Queue Queue;
struct _Queue
{
    Queue_Cell *current;
    Queue_Cell *last;
    bool isDynamicallyAllocated;
    bool dataManagement; // True if this lib should manage the allocation of the data
    /* Add another properties: length, etc... */
};

/**
 * @brief Check the existence of a queue
 * 
 * @param queue the queue
 * @return true if exist
 * @return false 
 */
bool queue_exist(Queue *queue);

/**
 * @brief Init the queue
 * 
 * @param queue the queue
 * @return Queue* a pointer to the queue (needed if you want to allocate the queue dynamically,
 *  and if it is, then you must quit the queue by queue_quit() in order to free it in the end)
 */
Queue* queue_init(Queue *queue);

/**
 * @brief Check if the queue doesn't contain anything
 * 
 * @param queue the queue
 * @return true if the queue is empty
 * @return false 
 */
bool queue_isEmpty(Queue *queue);

/**
 * @brief Destroy the queue
 * 
 * @param queue the queue
 * @return Queue* NULL (needed if you allocated dynamically the queue and want
 *  to secure the pointer to the queue)
 */
Queue* queue_quit(Queue *queue);

/**
 * @brief Delete the first element of the queue. Warning! If you have used queue_createData() and 
 *  the type of your data structure contain dynamically allocated variables, free those variables
 *  before using this function
 * 
 * @param queue the queue
 */
void queue_pop(Queue *queue);

/**
 * @brief Add an element in the last of the queue. The data of element must be already
 *  dynamically allocated (by queue_createData() or malloc()) and filled by yourself.
 *  Note that if you don't manage yourself the data allocation and freeing, you must use
 *  queue_createData() in order to tell the library to manage it (allocation and freeing).
 *  You can create a new function of push costumized in your need for creation of data
 *  (allocation), add of the data items (fill properties) and call queue_pushData() in the end.
 * 
 *  For example: 
 *      bool queue_push(Queue *queue, int age, const char *name) 
 *  where data is an instance of a structure containing 'age' and 'name': 
 *      struct{int age, char name[20]}
 * 
 * @param queue the queue
 * @param data the data of the new element
 * @return true if the operation succeed
 * @return false 
 */
bool queue_pushData(Queue *queue, void *data);

/**
 * @brief Allocate (dynamically) memory spaces for a new data. Warning! If you manage yourself the allocation
 *   and freeing of the data, so never use this function for the concerned queue.
 * 
 * @param queue the queue
 * @param sizeofDataType the size of the data type
 * @param numberofData the number of data (length of the array if it is an array, 1 otherwise)
 * @return void* pointer of the new data
 */
void* queue_createData(Queue *queue, size_t sizeofDataType, unsigned int numberofData);

/**
 * @brief Return the first element of the queue
 * 
 * @param queue the queue
 * @return void* the pointer to the first data
 */
void* queue_getFirst(Queue *queue);

#endif // QUEUE_H_INCLUDED
