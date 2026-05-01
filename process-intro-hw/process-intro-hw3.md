## Question 3
Switch the order of the processes: -l 1:0,4:100. What happens now? Does switching the order matter? Why? (As always, use -c
and -p to see if you were right)

### Answer 
Now the first process starts an I/O  operation, and the CPU is idle, so it can start working on the second process. 
So switching the order of the processes matters because it changes the order in which the processes are executed. 
More precisely switching the order matter for  efficiency because now the CPU is not idle while the first process is waiting for the I/O operation to complete

