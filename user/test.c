#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fs.h"
#include "user.h"

int main(void){
    printf(2, "............................................\n");
    for (int i = -3; i < 2; i++) {
        nice(2, i);
        ps();
        printf(2, "............................................\n");
    }
    exit();
}

