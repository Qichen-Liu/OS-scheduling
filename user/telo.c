#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"
#include "kernel/fs.h"


void dummy(int num){
    int x = 1;
    for (int i = 1; i < 300; i++) {
        if (x != 0) {
            x = num % i;
        }
    }
}

int main(void) {

    // set parent's priority to -20
    // make sure parent is great likely to run first 
    // set child tickets at same time
    nice(getpid(), -20);

    int pid1 = fork();
    
    if (pid1 == 0) { // enter child
        int childpid = getpid();
        printf(1, "Child 1 (PID %d) starts processing\n", childpid);
        nice(childpid, 5);
        printf(1, "Child 1 Infomation:\n");
        ps();
        for (int i = 0; i < 200000000; i++){
            // run dummy function
            dummy(i);
            if (i == 100000000) {
                printf(1, "Child 1 (PID %d) 50% Done\n", childpid);
            }
        }
        printf(1, "Child 1 (PID %d) has finished\n", childpid);
        exit();
    }
    int pid2 = fork();
    
    if (pid2 == 0) { // enter child
        int childpid = getpid();
        printf(1, "Child 2 (PID %d) starts processing\n", childpid);

        nice(childpid, -10);
        printf(1, "Child 2 Infomation:\n");
        ps();
        
        for (int i = 0; i < 200000000; i++){
            // run dummy function
            dummy(i);
            if (i == 100000000) {
                printf(1, "Child 2 (PID %d) 50% Done\n", childpid);
            }
        }
        printf(1, "Child 2 (PID %d) has finished\n", childpid);
        exit();
    }

    // int pid3 = fork();
    
    // if (pid3 == 0) { // enter child
    //     int childpid = getpid();

    //     // the nice function will change ticket to 3000
    //     nice(childpid, -5);
    //     printf(1, "Child 3 Infomation:\n");
    //     ps();
    //     for (int i = 0; i < 10000000; i++){

    //         // run dummy function
    //         dummy(i);
    //         if (i == 0) {
    //             printf(1, "PID %d starts processing\n", childpid);
    //         }
    //     }
    //     printf(1, "PID %d has finished\n", childpid);
    //     exit();
    // }

    // wait();
    wait();
    wait();
    exit();
}