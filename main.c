#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment(void *args);
int soma = 0;
int range;

int main(void) {
        
        scanf("%d", &range);
        
        int matriz[range][range];
        for (int i =  0; i < range; i++) {
                for (int j = 0; j < range; j++) {
                        scanf("%d", &matriz[i][j]);
                }
        }
        
        int *linha;
        
        pthread_t threads[range];
        for (int i = 0; i< range; i++) {
                linha = matriz[i];
                if (pthread_create(&(threads[i]), NULL, increment, linha)) {
                        printf("Erro na criação da thread %d", i);
                }
        }

        for (int i = 0; i < range; i++) {
                pthread_join(threads[i], NULL);
        }
        //printf("\nSoma das linhas: %d", soma);
        printf("%d", soma);
        return 0;
}

void *increment(void *args) {
        pthread_mutex_lock(&mutex);

        int *linha = (int*)args;
        
        //int sub = soma;

        for (int i = 0; i < range; i ++) {
                soma += linha[i];
        }
        //sub = soma - sub;

        //printf("\nSoma linha: %d", sub);
        pthread_mutex_unlock(&mutex);
}