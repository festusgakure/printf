#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t my_pid, parent_pid, fpid;

    my_pid = getpid();
    parent_pid = getppid();
 	
    fpid =fork();
    printf("My PID is %d\n", my_pid);
    printf("My parent's PID is %d\n", parent_pid);
     printf("My parent's PID is %d\n", fpid);

    return 0;
}

