# QueueC

Queue manager library in C

# Get started

* Define Q_DATA_TYPE as a variable type that you want to store in the queue:

    - before including ``"queueC.h"``

        #define Q_DATA_TYPE int // Or something else

    - OR directly in the file ``"queueC.h"``

        #ifndef Q_DATA_TYPE
        #define Q_DATA_TYPE int // Or something else
        #endif //Q_DATA_TYPE

* Define Q_DATA_LENGTH as the legth of the data if it is an array (1 if not):

    - before including ``"queueC.h"``

        #define Q_DATA_LENGTH 1 // Or something else

    - OR directly in the file ``"queueC.h"``

        #ifndef Q_DATA_LENGTH
        #define Q_DATA_LENGTH 1 // Or something else
        #endif //Q_DATA_LENGTH

* Include the header file ``"queueC.h"`` in your source code
    
    #include "queueC.h"

* When you are about to compile

    - in an IDE, find and add to the linker the file ``libqueueC.a``

    - with gcc, if ``libqueueC.a`` is in the current directory (otherwise, write the whole path)

        gcc -Wall -O2 main.c -s libqueueC.a

# Use and Example

Go to [example directory](example)

# Compilation of the library

If you to compile again the library, delete ``libqueueC.a`` and run the following command

    gcc -Wall -O2  -c queueC.c -o queueC.o
    ar -r -s libqueueC.a queueC.o

# Limitation

The type of data stored in the queue cannot be changed throughout the program. If you want to have another queue with a different data type, you have to implement the queue yourself or migrate to another language such as C++, python,... which manages queues.

# License

Project under [MIT LICENSE](LICENSE-MIT)