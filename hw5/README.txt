README
======

This package includes the following files.

|-- ProducerConsumer.java [This is the driver program which will be used to create an instance of the Circular buffer, and create and wait for one or more threads of producer and consumer.] (Skeleton Code provided)
|-- Producer.java [Each instance of a producer generates a single character randomly and inserts into the buffer, and reports the location and the time the character was inserted into the buffer] (Skeleton Code provided)
|-- Consumer.java [Each instance of a consumer reads a character from the buffer and reports the location and the time the character was read from the buffer.]
|-- Buffer.java [Creates a circular buffer whose size is passed as an argument to it.]
|-- Makefile [For compiling, cleaning and taring.]
|-- README.txt [This file]


Questions:

1. The problem of producer consumer is solved using __Mutex Locks___. - 1 point
	a. Mutex Locks
	b. Semaphores

2. What two functions defined in Java are used for synchronization between producers and consumers in your program? __wait()__ and __notify()__. - 2 points

3. In which function do you override the body to define the new body of a thread in java? __run()__. - 1 point

4. Which function is used to wait for a thread to finish and come back to calling program i.e. for a thread to die? __join()__. - 1 point

NOTE:

Lab systems by default use Java 8 which supports only millisecond timestamp. To use Java 11, which supports nanosecond timestamp, use the following two commands.

	$ export PATH=/usr/lib/jvm/jre-11-openjdk/bin/:$PATH

	$ export LD_LIBRARY_PATH=/usr/lib/jvm/jre-11-openjdk/lib/:$LD_LIBRARY_PATH


