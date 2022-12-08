#include "print.h"

void print()
{
    printf("getpid:  %d\n",getpid());
    printf("getppid: %d\n",getppid());
    printf("getpgrp: %d\n",getpgrp());
    printf("getuid:  %d\n",getuid());
    printf("geteuid: %d\n",geteuid());
    printf("getgid:  %d\n",getgid());
    printf("getegid: %d\n",getegid());
    puts("===========================");
    printf("CHILD_MAX: %d\n",sysconf(_SC_CHILD_MAX));
}