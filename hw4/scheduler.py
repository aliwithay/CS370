import csv
import sys


def fcfs(processlist):
    # First Come First Serve Scheduler
    processlist.sort(key=lambda x: x[1])
    currenttime = 0
    processes = []          # [Process ID, Wait Time, Turnaround Time]
    gantt = []              # [Process ID, Start Time, Finish Time]
    for process in processlist:
        if process[1] > currenttime:        # If no process has arrived, IDLE.
            gantt.append(["IDLE", currenttime, process[1]])
            currenttime = process[1]
        gantt.append([process[0], currenttime, currenttime + process[2]])
        processes.append(
            [process[0], currenttime-process[1], currenttime + process[2] - process[1]])
        currenttime = currenttime + process[2]
    totalwait = 0
    totalturnaround = 0
    for process in processes:               # Format output
        output = ""
        totalwait += process[1]
        totalturnaround += process[2]
        print("Process " + str(process[0]) + ":"),
        print("Waiting time: " + str(process[1]) + ","),
        print("Turnaround time: " + str(process[2]))
    print("")
    print("Gantt Chart:")
    for process in gantt:
        print("Process " + str(process[0]) + ":"),
        print(str(process[1])),
        print(str(process[2]))
    print("")
    waittime = float(totalwait) / len(processes)
    print("Average waiting time: " + str(waittime))
    turnaroundtime = float(totalturnaround) / len(processes)
    print("Average turnaround time: " + str(turnaroundtime))
    throughput = len(processes) / float(currenttime)
    print("Throughput: " + str(throughput))


def sjf(processlist):
    # Shortest Job First Scheduler
    arrivequeue = [row[:] for row in processlist]
    execqueue = [row[:] for row in processlist]
    arrivequeue.sort(key=lambda x: x[1])
    execqueue.sort(key=lambda x: x[2])
    currenttime = 0
    processes = []              # [Process ID, Wait Time, Turnaround Time]
    gantt = []                  # [Process ID, Start Time, Finish Time]
    while len(processes) < len(processlist):
        idle = True
        for process in execqueue:
            if (process[1] <= currenttime):
                idle = False
                gantt.append([process[0], currenttime,
                              currenttime + process[2]])
                processes.append(
                    [process[0], currenttime - process[1], currenttime + process[2] - process[1]])
                currenttime = currenttime + process[2]
                execqueue.remove(process)
                arrivequeue.remove(process)
        if idle:
            gantt.append(["IDLE", currenttime, arrivequeue[0][1]])
            currenttime = arrivequeue[0][1]
    totalwait = 0
    totalturnaround = 0
    for process in processes:
        output = ""
        totalwait += process[1]
        totalturnaround += process[2]
        print("Process " + str(process[0]) + ":"),
        print("Waiting time: " + str(process[1]) + ","),
        print("Turnaround time: " + str(process[2]))
    print("")
    print("Gantt Chart:")
    for process in gantt:
        print("Process " + str(process[0]) + ":"),
        print(str(process[1])),
        print(str(process[2]))
    print("")
    waittime = float(totalwait) / len(processes)
    print("Average waiting time: " + str(waittime))
    turnaroundtime = float(totalturnaround) / len(processes)
    print("Average turnaround time: " + str(turnaroundtime))
    throughput = len(processes) / float(currenttime)
    print("Throughput: " + str(throughput))


def rr(processlist, tquantum):
    # Round Robin Scheduling
    execqueue = [row[:] for row in processlist]
    execqueue.sort(key=lambda x: x[1])
    currenttime = 0
    processes = []          # [Process ID, Waiting Time, Turnaround Time]
    gantt = []              # [Process ID, Start Time, Finish Time]
    while len(execqueue) > 0:           # While queue is not empty
        execqueue.sort(key=lambda x: x[1])
        process = execqueue[0]
        if (process[1] > currenttime):
            gantt.append(["IDLE", currenttime, process[1]])
            currenttime = process[1]
            continue
        if (process[2] < tquantum):
            currenttime += process[2]
            for row in processlist:
                if row[0] == process[0]:
                    i = processlist.index(row)
            gantt.append([process[0], currenttime - process[2], currenttime])
            processes.append([process[0], currenttime - processlist[i][1] - processlist[i]
                              [2], currenttime - processlist[i][1]])
            execqueue.remove(process)
            continue
        process[2] -= tquantum
        currenttime += tquantum
        if (process[2] != 0):
            execqueue.append([process[0], currenttime, process[2]])
        if (process[2] == 0):
            for row in processlist:
                if row[0] == process[0]:
                    i = processlist.index(row)
                    processes.append([process[0], currenttime - processlist[i][1] - processlist[i]
                                      [2], currenttime - processlist[i][1]])
        gantt.append([process[0], currenttime - tquantum, currenttime])
        execqueue.remove(process)
    totalwait = 0
    totalturnaround = 0
    print("Time Quantum: " + str(tquantum))
    print("")
    for process in processes:
        output = ""
        totalwait += process[1]
        totalturnaround += process[2]
        print("Process " + str(process[0]) + ":"),
        print("Waiting time: " + str(process[1]) + ","),
        print("Turnaround time: " + str(process[2]))
    print("")
    print("Gantt Chart:")
    for process in gantt:
        print("Process " + str(process[0]) + ":"),
        print(str(process[1])),
        print(str(process[2]))
    print("")
    waittime = float(totalwait) / len(processes)
    print("Average waiting time: " + str(waittime))
    turnaroundtime = float(totalturnaround) / len(processes)
    print("Average turnaround time: " + str(turnaroundtime))
    throughput = len(processes) / float(currenttime)
    print("Throughput: " + str(throughput))


inputFile = open(sys.argv[1], 'r')
quantum = int(sys.argv[2])
processor = []
filereader = csv.reader(inputFile)
next(filereader)
for row in filereader:
    pInfo = []
    for a in row:
        pInfo.append(int(a))
    processor.append(pInfo)
print("###################### FCFS ######################")
fcfs(processor)
print("\n")
print("###################### SJFS ######################")
sjf(processor)
print("\n")
print("###################### Round Robin Scheduler ######################")
rr(processor, quantum)
