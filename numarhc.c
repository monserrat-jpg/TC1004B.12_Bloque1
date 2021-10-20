#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    int pid = fork();
    if(pid == 0){
        dup2(1, fd[0]);
        execlp("wc","wc","-1",NULL);
    }else{
        dup2(1, fd[0]);
        execlp("ls","ls",NULL);  
    }
    return 0;
}