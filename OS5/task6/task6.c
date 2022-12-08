#include <stdio.h> 
#include <stdlib.h> 
#include <getopt.h>  
#include <string.h> 

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("set -e [variable name] -v [variable value]\n");
        return 0;
    }
    char* opts = "e:v:";
    char value[1024];
    char varname[1024];
    int opt;
    while ((opt = getopt(argc, argv, opts)) != -1) {
        switch (opt) {
        case 'e':
            strcpy(varname, optarg);
            break;
        case 'v':
            strcpy(value, optarg);
            break;
        default:
            printf("wrong options\n");
        }
    }
    if (setenv(varname, value, 1) == 0) {
        printf("Environment variable %s=%s set\n", varname, value);
    }
    else {
        printf("can`t set\n");
    }
    return 0;
}
