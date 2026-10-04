#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int counter = 0;
pthread_mutex_t lock;

void *increment(void *arg) {
    int id = *(int *)arg;
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    int id1 = 1, id2 = 2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, increment, &id1);
    pthread_create(&t2, NULL, increment, &id2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final counter value = %d (expected 200000)\n", counter);

    pthread_mutex_destroy(&lock);
    return 0;
}