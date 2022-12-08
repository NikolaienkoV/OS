#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define DEFAULT_BUFFER_SIZE 127
#define MIN_BUFFER_SIZE 10
#define DEFAULT_COUNT_OF_ARGS 20
#define STOP_WORD "stop"
#define ECANT_FORK_PROCESS -1
#define ECANT_EXEC -2
#define EWAIT -3
#define ETOO_MANY_ARGS -1;
#define true 1;
#define false 0;
static int buffer_size;
void usage() {
    printf("hello!\n");
}
int _getline(char *buf, int size) {
    int i = 0;
    long count = 0;
    int ch;
    while ((ch = fgetc(stdin)) != EOF) {  // Read until EOF ...
        count++;
        if (ch == '\n') {  // ... or end of line
            break;
        }
        if (i + 1 < size) {
            buf[i++] = ch;
        }
    }
    buf[i] = '\0';
    if (i == 0) {
        return EOF;
    }
    return count - size > 0 ? 0 : 1;
}
int runCommand(char *command, char **args) {
    int pcid = fork();
    if (pcid == -1) {
        return ECANT_FORK_PROCESS;
    }
    if (pcid == 0) { //child
        execv(command, args);
        return ECANT_EXEC;
    }
    if (pcid != 0) { //parent
        int status;
        wait(&status);
        if (!WIFEXITED(status)) {
            return EWAIT;
        }
    }
    return 0;
}
int mySystem(char *commandWithArgs, int bufferSize, int maxCountOfArgs) {
    int arrSize = maxCountOfArgs + 2; //plus cell for command line and cell for NULL
    char **strings = (char **) malloc(sizeof(char*) * arrSize);
    int maxCountElemInArr = arrSize - 1;
    int j = 0;
    int lastElemIndex = -1;
    int prevSymbolIsSpace = true;
    for (int i = 0; i <= (strlen(commandWithArgs)); i++) {
        if (lastElemIndex >= maxCountElemInArr) {
            for (int i = 0; i <= lastElemIndex; i++) {
                free(strings[i]);
            }
            free(strings);
            return ETOO_MANY_ARGS;
        }
        if (commandWithArgs[i] == ' ' || commandWithArgs[i] == '\0') {
            if(!prevSymbolIsSpace){
                strings[lastElemIndex][j]='\0';
            }
            prevSymbolIsSpace = true;
        } else {
            if(prevSymbolIsSpace){
                lastElemIndex++;
                strings[lastElemIndex] = (char*)malloc(sizeof(char) * bufferSize);
                j = 0;
            }
            strings[lastElemIndex][j] = commandWithArgs[i];
            j++;
            prevSymbolIsSpace = false;
        }
    }
    strings[++lastElemIndex] = NULL;
    char* command = strings[0];
    int status = runCommand(command, ++strings);
    strings--;
    for (int i = 0; i <= lastElemIndex; i++) {
       free(strings[i]);
    }
    free(strings);

    return status;
}
void printStatus(int status) {
    switch (status) {
        case 0:
            puts("subprogram was successfully completed");
            break;
        case ECANT_FORK_PROCESS:
            puts("FORK ERROR");
            break;
        case ECANT_EXEC:
            puts("COMMAND ERROR");
            break;
        case EWAIT:
            puts("WAIT ERROR");
            break;
    }
}
int main(int argc, char **argv) {
    buffer_size = DEFAULT_BUFFER_SIZE;
    const struct option long_opt[] = {
            {"help",   0, 0, 'h'},
            {"buffer", 1, 0, 'b'}
    };
    int c;
    while ((c = getopt_long(argc, argv, "hb:", long_opt, NULL)) != -1) {
        switch (c) {
            case 'h':
                usage(argv[0]);
                break;
            case 'b':
                buffer_size = atoi(optarg);
                if (buffer_size < MIN_BUFFER_SIZE) {
                    usage();
                    return EXIT_FAILURE;
                }
                break;
            case '?':
                usage();
                return EXIT_FAILURE;
            default:
                usage();
                return EXIT_FAILURE;
        }
    }
    char *buffer = (char *) malloc(sizeof(char) * buffer_size);
    char *login = getlogin();
    int status;
    while (1) {
        printf("[%s]$ ", login);
        if (_getline(buffer, buffer_size)) {
            if (!strcmp(STOP_WORD, buffer)) {
                puts("wait 3 seconds...");
                sleep(3);
                printf("\e[1;1H\e[2J");
                return EXIT_SUCCESS;
            }
            status = mySystem(buffer,buffer_size,DEFAULT_COUNT_OF_ARGS);
            printStatus(status);
        } else {
            puts("command too long for exists buffer size.\nPlease restart program with more big buffer size\n");
        }
    }
}
