6#include <stdio.h> 
#include <stdlib.h> 
#include <getopt.h>  
#include <string.h> 
#include <unistd.h>

extern char** environ;

int main(int argc, char** argv) {
    if (argc == 1) {
        if (clearenv() == 0)
            printf("variables deleted\ncan set -e [variable name]\n");
        return 0;
    }
    char* opts = "e:";
    char varname[1024];
    int opt;
    while ((opt = getopt(argc, argv, opts)) != -1) {
        switch (opt) {
        case 'e':
            strcpy(varname, optarg);
            if (unsetenv(varname) == 0) printf("variable %s deleted\n", varname);
            break;
        default:
            printf("wrong options\n");
        }
    }
    int i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }

    return 0;
}
