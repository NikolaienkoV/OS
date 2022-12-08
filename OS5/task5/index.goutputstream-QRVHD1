#include <stdio.h> 
#include <stdlib.h> 
#include <getopt.h>  
#include <string.h> 

int main(int argc, char** argv) {
    if (argc == 1) {
        printf("set -e [variable name] to see the value\n");
        return 0;
    }
    char* str;
    char* opts = "e:";
    char varname[1024];
    int opt;
    while ((opt = getopt(argc, argv, opts)) != -1) {
        switch (opt) {
        case 'e':
            strcpy(varname, optarg);
            str = getenv(varname);
            printf("%s = %s\n", varname, str);
            break;
        default:
            printf("wrong options\n");
        }
    }
    return 0;
}
