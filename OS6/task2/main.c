#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define delayTimeInSec 5

static unsigned long long counter;
void wait();

void wait(){
    __time_t start = time(NULL);
    while(time(NULL)-start<=delayTimeInSec){
        counter++;
    }
}
int main() {
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        printf("Process - child\n");
        wait();
        printf("Child counter: %llu\n", counter);
    } else if (pid > 0) {
        printf("Process - father, child pid: %d\n", pid);
        wait();
        printf("Father counter: %llu\n", counter);
    } else {
        printf("Ошибка вызова fork, потомок не создан\n");
    }
    return 0;
}
