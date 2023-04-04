#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user.h"

int strToInt(char *arg){
    int val;
    if(arg[0] == '-'){
        char *tmp = "";
        strcpy(tmp, arg+1);
        val = 0 - atoi(tmp);
    }else {
        val = atoi(arg);
    }
    return val;
}

int main(int argc, char *argv[]){
    int priority, pid;
    if (argc != 3) {
        printf(2, "Usage: nice pid priority\n");
        exit();
    }
    pid = atoi(argv[1]);
    priority = strToInt(argv[2]);
    if (priority < -20 || priority > 19){
        printf(2,"Invalid priority [-20, 19]!\n");
        exit();
    }
  nice(pid, priority);
  exit();
}
