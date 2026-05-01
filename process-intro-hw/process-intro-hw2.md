## Question
2. Now run with these flags: ./process-run.py -l 4:100,1:0.
These flags specify one process with 4 instructions (all to use the CPU), and one that simply issues an I/O and waits for it to be done.
How long does it take to complete both processes? Use -c and -p to find out if you were right.

### Answer
I expect it to take 4 cycles to complete the first process, then the cpu stays idle for the 5 cycles needed to complete an I/O request, totaling 9.

```
Time        PID: 0        PID: 1           CPU           IOs
  1        RUN:cpu         READY             1          
  2        RUN:cpu         READY             1          
  3        RUN:cpu         READY             1          
  4        RUN:cpu         READY             1          
  5           DONE        RUN:io             1          
  6           DONE       BLOCKED                           1
  7           DONE       BLOCKED                           1
  8           DONE       BLOCKED                           1
  9           DONE       BLOCKED                           1
 10           DONE       BLOCKED                           1
 11*          DONE   RUN:io_done             1          

Stats: Total Time 11
Stats: CPU Busy 6 (54.55%)
Stats: IO Busy  5 (45.45%)
```

I unndershoot it by 2, I was correct remembering the number of cycles needed for an I/O request, but I didn't account for the cycle needed to initiate it and I didn't cound the last cycle (potentially trivial, but it doesn't hurt to take note of it)