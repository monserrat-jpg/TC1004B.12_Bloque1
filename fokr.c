#include <stdio.h>
#include <unistd.h>

int main(){
    int pid = fork();
    if(pid == 0 ){
        printf("Es el proceso hijo\n");
    }
    else{
        printf("Es el proceso padre, el hijo es %d\n", pid);
    }
    return 0;
}