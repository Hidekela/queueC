# QueueC

_Queue manager library in C_

![queue.png](queue.png)

## Getting started

* Include the header file `"queueC.h"` in your source code

```C
    #include "queueC.h"
```

* When you are about to compile

    - in an IDE, find and add to the linker the file `libqueueC.a`

    - with gcc, if `libqueueC.a` is in the current directory (otherwise, write the whole path)

```
    gcc -Wall -O2 main.c -s libqueueC.a
```

## Use and Examples

You will find in the header file how to use each function. 
Go to [example directory](example) to see usage examples

## Compilation of the library

If you to compile again the library, delete `libqueueC.a` and run the following command

    gcc -Wall -O2  -c queueC.c -o queueC.o
    ar -r -s libqueueC.a queueC.o

## License

Project under [MIT LICENSE](LICENSE-MIT)