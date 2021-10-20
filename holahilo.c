
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10000
int saldo;
pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;



//gcc holahilo.c -o holahilo
//./holahilo
void *printHola(void *arg){

    int saldoLocal;
    pthread_mutex_lock(&lockSaldo);

    saldoLocal = saldo;
    saldoLocal+=100;
    saldo = saldoLocal;

    pthread_mutex_unlock(&lockSaldo);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    saldo = 0;
    for(int i = 0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, printHola, NULL);
    }

    for(int i = 0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("El valor del saldo es %d", saldo);
    pthread_exit(NULL);
}