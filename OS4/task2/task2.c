#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char** argv) {
    if (argc == 1) {
        printf("getopt test\n");
        return 0;
    }
    char* opts = "ho:c";
    char* out_file_name;
    int opt;
    while ((opt = getopt(argc, argv, opts)) != -1) {
        switch (opt) {
        case 'h':
            printf("-h Help\n-o [out out_file_name]\n-c special operating mode\n");
            break;
        case 'o':
            out_file_name = optarg;
            printf("Outfile - %s\n", out_file_name);
            break;
        case 'c':
            printf("Special operating mode\n");
            break;
        }
    }
    return 0;
}
