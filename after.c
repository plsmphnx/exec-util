#include <stdlib.h>
#include <unistd.h>
#include "util/execw.c"

static inline char split(char *arg) {
    switch (arg[0]) {
        case ';': case '&': case '|': return arg[1] ? 0 : arg[0];
        default: return 0;
    }
}

int main(int argc, char *argv[]) {
    int start, index, result;
    char join;
    for (start = index = 1 ;; start = ++index) {
        while (argv[index] && !(join = split(argv[index]))) ++index;
        if (!join) return execvp(argv[start], argv+start);
        argv[index] = 0;
        result = execw(argv[start], argv+start);
        switch (join) {
            case '&': if (result) return result; break;
            case '|': if (!result) return 0; break;
        }
    }
}
