#include <stdlib.h>
#include <unistd.h>
#include "util/execw.c"

char split(char *arg) {
    switch (arg[0]) {
        case ';': case '&': case '|': return arg[1] ? 0 : arg[0];
        default: return 0;
    }
}

int main(int argc, char *argv[]) {
    int start = 1, index = 1, result;
    char join;
    while (1) {
        while (argv[index] && !(join = split(argv[index]))) index++;
        if (!argv[index]) break;
        argv[index++] = 0;
        result = execw(argv[start], argv+start);
        switch (join) {
            case ';': break;
            case '&': if (result) return result; break;
            case '|': if (!result) return 0; break;
        }
        start = index;
    }
    return execvp(argv[start], argv+start);
}
