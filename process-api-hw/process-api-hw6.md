## Question 6
Finally, use both -t and -F together. This shows the final process tree, but then asks you to fill in the actions that took place. By looking at the tree, can you determine the exact actions that took place?
In which cases can you tell? In which can’t you tell? Try some different random seeds to delve into this question

### Answer:
When a process that spawned many children exits, the children get all adopted by the root process, even if they were not directly forked by the root process. This loses the original parent child information.