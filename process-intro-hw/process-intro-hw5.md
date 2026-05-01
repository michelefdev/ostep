## Question 5
Now, run the same processes, but with the switching behavior set to switch to another process whenever one is WAITING for I/O (-l 1:0,4:100 -c -S SWITCH_ON_IO). What happens now? Use -c
and -p to confirm that you are right.

### Answer
The default behaviour seems to be SWITCH_ON_IO, because if I run the same command without the -S flag, I get the same result as running it with the -S SWITCH_ON_IO flag.
I also checked the behaviour for the flag SWITCH_ON_END, and I can confirm that it serves the same output as running the program with the 4:100,1:0 process list (question 2).

``` shell
py -l 1:0,4:100 -c -S SWITCH_ON_IO -cp
```

```
Time        PID: 0        PID: 1           CPU           IOs
  1         RUN:io         READY             1
  2        BLOCKED       RUN:cpu             1             1
  3        BLOCKED       RUN:cpu             1             1
  4        BLOCKED       RUN:cpu             1             1
  5        BLOCKED       RUN:cpu             1             1
  6        BLOCKED          DONE                           1
  7*   RUN:io_done          DONE             1

Stats: Total Time 7
Stats: CPU Busy 6 (85.71%)
Stats: IO Busy  5 (71.43%)
```