## Question 8
Now run with some randomly generated processes using flags 
-s 1 -l 3:50,3:50 or 
-s 2 -l 3:50,3:50 or 
-s 3 -l 3:50,3:50.

See if you can predict how the trace will turn out. 
What happens when you use the flag -I IO_RUN_IMMEDIATE versus that flag -I IO_RUN_LATER?
What happens when you use the flag -S SWITCH_ON_IO versus -S SWITCH_ON_END?

### Answer
#### -s 1 -l 3:50,3:50 
##### RUN_IMMEDIATE vs RUN_LATER
This creates **two processes**, the first one does one CPU instruction, and two I/O requests. The second process consist only of CPU instructions. 
So, the first I/O request of the first process will start, then the second process will start esecuting and finish before the first process can finish its I/O operations. 
So the RUN_* flags won't make a difference in the CPU utilization.

##### SWITCH_ON_IO vs SWITCH_ON_END
With the SWITCH_ON_IO flag, the CPU will switch to the second process as soon as the first process starts its I/O operation, instead of waiting for it to complete. This will lead to a better CPU utilization.

#### -s 2 -l 3:50,3:50 
##### RUN_IMMEDIATE vs RUN_LATER
This creates **two processes** the first one makes two I/O requests and one CPU instruction. The second process consists of one CPU instruction and two I/O requests (in this order). 


##### SWITCH_ON_IO vs SWITCH_ON_END
The SWITCH_ON_IO flag increases the CPU utilization, because it allows the CPU to switch to the second process as soon as the first process starts its I/O operation, instead of waiting for it to complete.


#### -s 3 -l 3:50,3:50 
##### RUN_IMMEDIATE vs RUN_LATER


##### SWITCH_ON_IO vs SWITCH_ON_END


