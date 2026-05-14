## Question 5
One last flag to explore is the -F flag, which skips intermediate steps and only asks to fill in the final process tree. Run ./fork.py -F and see if you can write down the final tree by looking at the series of actions generated. Use different random seeds to try this a few times.

### Answer

Done. Just one example:

```
Action: a forks b
Action: b forks c
Action: b forks d
Action: c EXITS
Action: b EXITS

                        Final Process Tree:
                               a
                               └── d
```

