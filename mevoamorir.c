#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void handle(int signal){
    printf("xfghjklgffs %d\n", signal);
}

int main(){
    signal(2, handle);
    while(1){
        printf("ya jala\n");
        sleep(1);
    }
    return 0;
}