README
======

This package includes the following files.

|-- Scheduler.py [This is the driver program which will be used to test different scheduling algorights for a given processes.csv file. The program implements three functions, namely fcfs
|-- (First Come First Serve), sjf (Shortest Job First) and rr (Round Robin). It outputs the gantt chart, individual and average waiting time and individual and average turnaround times.


Questions:

1. What is the other name for Shortest Job First Preemptive Algorithm? 
Answer: Shortest Time Remaining.

2. What are the 5 different states a process can be in scheduling (Look into process state diagram)? 
Answer: Ready, Wait, Running, Blocked, Completed

3. Shortest Job First is like Priority Scheduling with the priority based on ______ of the process? 
Answer: Burst time.

4. ________ effect is the primary disadvantage of First Come First Serve Scheduling algorithm. 
Answer: Convoy

5. How does Multi Level Feedback queue prevent starvation of processes that waits too long in lower priority queue? 
Answer: It uses a different scheduling algorith for lower priority queues.