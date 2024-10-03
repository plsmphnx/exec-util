#include <stdlib.h>
#include <unistd.h>

static inline char skip(char *arg) {
    switch (arg[0]) {
        case ';': case '&': case '|': return arg[1];
        default: return 1;
    }
}

int main(int argc, char *argv[]) {
    int start, index, result;
    char *arg;
    for (;;) for (start = index = 1; argv[start]; start = ++index) {
        while ((arg = argv[index]) && skip(arg)) ++index;
        if (!arg || !fork()) {
            argv[index] = 0;
            return execvp(argv[start], argv+start);
        }
        result = wait(&result) ? WEXITSTATUS(result) : EXIT_FAILURE;
        switch (arg[0]) {
            case '&': if (result) return result; break;
            case '|': if (!result) return result; break;
        }
    }
}
