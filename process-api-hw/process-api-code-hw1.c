/*
Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100). 
What value is the variable in the child process?
What happens to the variable when both the child and parent change the value of x?
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    // 1. Set the variable before calling fork()
    int x = 100;

    // 2. Call fork()
    int rc = fork();

    if (rc < 0) {
        // Fork failed, the program exits
        return 1;
    } 
    else if (rc == 0) {
        // Child process
        printf("Child sees x as: %d\n", x);
        x = 200;
        printf("Child changed x to: %d\n", x);
    } 
    else {
        // Parent process
        printf("Parent sees x as: %d\n", x);
        x = 300;
        printf("Parent changed x to: %d\n", x);
    }
    return 0;
}

/*
The variable in the child process is 100.
When the parent changes the value of x, the child's value of x is not affected and
vice versa.
After the fork the two processes have their own copy of the variable x.

OUTPUT:
Parent sees x as: 100
Parent changed x to: 300
Child sees x as: 100
Child changed x to: 200
*/