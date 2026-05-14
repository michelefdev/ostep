## Question 3
Now, switch the output by using the -t flag (e.g., run ./fork.py
-t). Given a set of process trees, can you tell which actions were
taken?

### Answer
Yes, I can.

I noticed that orphan process behave exactly like I woul;d expect in a linux system, when the parent exits the child process is not adopted by the "nearest" ancestor in the tree, but instead it is adopted by the root process:
```
Action: g forks i
                               a
                               ├── d
                               │   └── f
                               │       ├── g
                               │       │   └── i
                               │       └── h
                               └── e
Action: f EXITS
                               a
                               ├── d
                               ├── e
                               ├── g
                               ├── i
                               └── h
```