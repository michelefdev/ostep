/*
Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    // 1. Open a file
    int fd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // 2. Call fork()
    int rc = fork();

    if (rc < 0) {
        // Fork failed, the program exits
        return 1;
    } 
    else if (rc == 0) {
        // Child process
        printf("Child writing to file...\n");
        write(fd, "Child writes.\n", 2);
    } 
    else {
        // Parent process
        printf("Parent writing to file...\n");
        write(fd, "Parent writes.\n", 5);
    }

    // 3. Close the file
    close(fd);

    return 0;
}

/*
OUTPUT:
Parent writing to file...
Child writing to file...

Both the child and parent can access the file descriptor returned by open().
It is not completely clear what "concurrently" means in this context, but
from what we studied up to this point there is no actual concurrency, 
but instead the OS switches between the two processes and each one can write
on the file once at a time.
*/
