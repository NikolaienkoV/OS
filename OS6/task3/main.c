#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void usage(char str[]) {
    puts("== usage ==");
    printf("you have error: %s\n", str);
    puts("== usage ==");
}int main(int argc, char **args) {
    // /////////////////////////////////////////////////
    // check input data
    // /////////////////////////////////////////////////
    if (argc != 2) {
        usage("you must enter one variable argument number - count of process");
        return EXIT_FAILURE;
    }int count_proc = atoi(args[1]);
    if (count_proc <= 0) {
        usage("count of process must be positive natural number");
        return EXIT_FAILURE;
    }
    if (count_proc >= sysconf(_SC_CHILD_MAX)) {
        usage("count of process must be less then count of CHILD_MAX");
        return EXIT_FAILURE;
    }
    // /////////////////////////////////////////////////
    // main logic
    // /////////////////////////////////////////////////
    int *proc_ids = (int *) malloc(sizeof(int));
    int pcid;
    for (int i = 0; i < count_proc; i++) {
        pcid = fork();
        if (pcid == 0) {
            printf("Process - child. pid:%d  ppid:%d\n", getpid(), getppid());
            for (;;) {}
        } else if (pcid > 0) {
            proc_ids[i] = pcid;
        } else {
            printf("Ошибка вызова fork, потомок не создан\n");
        }
    }
    sleep(1);
    char *command = (char *) malloc(sizeof(char) * 100);
    //get info about processes
    puts("================= processes info =================");
    for (int i = 0; i < count_proc; i++) {
        sprintf(command, "ps %d", proc_ids[i]);
        system(command);
    }
    //get all info
    puts("================= all info =================");
    system("ps");
    //kill my processes
    puts("================= kill my processes =================");
    for (int i = 0; i < count_proc; i++) {
        sprintf(command, "kill %d", proc_ids[i]);
        system(command);
    }
    //get all info
    puts("================= all info =================");
    system("ps");
    return 0;
}
