## Question 4
One interesting thing to note is what happens when a child exits;
what happens to its children in the process tree? To study this, let’s
create a specific example: ./fork.py -A a+b,b+c,c+d,c+e,c-.
This example has process ’a’ create ’b’, which in turn creates ’c’,
which then creates ’d’ and ’e’. However, then, ’c’ exits. What do
you think the process tree should like after the exit? What if you
use the -R flag?    

### Answer

Without the -R flag, the final process tree looks like this:
```
                               a
                               ├── b
                               ├── d
                               └── e
```
Confirming the "UNIX like" behavior where the children of a process are adopted by the root process when the parent exits.

With the -R flag, the process tree looks like this:
```
                           Process Tree:
                               a
                               └── b
                                   ├── d
                                   └── e
```
This reflects a more recent behavior where orphaned processes are adopted by their nearest surviving ancestor.
