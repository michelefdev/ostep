## Question 1
Run process-run.py with the following flags: -l 5:100,5:100.
What should the CPU utilization be (e.g., the percent of time the CPU is in use?) Why do you know this? Use the -c and -p flags to see if you were right.

### Answer
I expect the CPU utilization to be 100%, because as soon as one process ends, the other one starts immediately and it is not blocked by any I/O operation.

Time        PID: 0        PID: 1           CPU           IOs
  1   RUN:cpu          READY             1
  2   RUN:cpu          READY             1
  3   RUN:cpu          READY             1
  4   RUN:cpu          READY             1
  5   RUN:cpu          READY             1
  6    DONE         RUN:cpu             1
  7   RUN:cpu          READY             1
  8   RUN:cpu          READY             1
  9   RUN:cpu          READY             1
 10   RUN:cpu          READY             1

Stats: Total Time 10
Stats: CPU Busy 10 (100.00%)
Stats: IO Busy  0 (0.00%)

