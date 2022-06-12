/**
 * @file queueC.h
 * @author Hidekela (rhidekela@gmail.com)
 * @brief Queue manager library in C
 * 
 *                                       TO START
 *      
 *      Define Q_DATA_TYPE and Q_DATA_LENGTH respectively into a variable type that you want 
 *      to store in the queue and into the legth of the data if it is an array (1 if not).
 *      The type of the data stored in the queue cannot be changed durring the whole program.
 *      If you want to have another queue with a different type of data, implement the queue
 *      yourself or migrate to another language such as C++, python,... which manage queues.
 * 
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

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdbool.h>

/////////////////////////////////////////////   // |
/**                                             // |
 *   You can start the change from here         // |
 *                                              // |
 *   __________________________________  */     // |
                                                // |        define if it is not yet Q_DATA_TYPE 
    #ifndef Q_DATA_TYPE                         // |        into the data type you want to store 
    #define Q_DATA_TYPE int                     // |        in the queue :
    #endif //Q_DATA_TYPE                        // |        
                                                // |        int, char*, double, float, char**
    #ifndef Q_DATA_LENGHT                       // |        struct Node, struct Bidule*, etc...
    #define Q_DATA_LENGTH 1                     // |
    #endif //Q_DATA_LENGTH                      // |
                                                // |        and Q_DATA_LENGTH into the length of
/**  __________________________________         // |        the data if it's an array, 1 if not
 *                                              // |        
 *       Stop the change after here             // |        
 *                                       */     // |        
/////////////////////////////////////////////   // |        

typedef struct _Cell Cell;
struct _Cell
{
    Q_DATA_TYPE *data;
    Cell *next;
};

typedef struct _Queue Queue;
struct _Queue
{
    Cell *current;
    Cell *last;
    bool isDynamicallyAllocated;
    bool dataManagement; // True if this lib should manage the allocation of the data
    /* Add another properties: length, etc... */
};

bool queue_exist(Queue *queue);
Queue* queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
Queue* queue_quit(Queue *queue);
void queue_pop(Queue *queue);
bool queue_pushData(Queue *queue, Q_DATA_TYPE *data);
Q_DATA_TYPE* queue_createData(Queue *queue);
Q_DATA_TYPE* queue_getFirst(Queue *queue);

#endif // QUEUE_H_INCLUDED
