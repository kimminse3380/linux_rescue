#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

static void child()
{
    printf("child: %d.\n", getpid());
    exit(EXIT_SUCCESS);
}

static void parent(pid_t pic_c){
    printf("parent: %d, child of parent: %d\n", getpid(), pic_c);
    exit(EXIT_SUCCESS);
}

int main(void)
{
    pid_t ret;
    ret = fork();

    if(ret==-1)
        err(EXIT_FAILURE, "fork() failed");
    
    if(ret==0){
        child();
    }
    
    else{
        parent(ret);
    }
    err(EXIT_FAILURE, "shouldn't reach here");
}