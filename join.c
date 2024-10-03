#include <stdlib.h>
#include <unistd.h>

static inline char *split(char *arg) {
    switch (arg[0]) {
        case ';': case '&': case '|': return arg[1] ? NULL : arg;
        default: return NULL;
    }
}

int main(int argc, char *argv[]) {
    int start, index, result;
    char *join;
    for (;;) for (start = index = 1; argv[start]; start = ++index) {
        while (argv[index] && !(join = split(argv[index]))) ++index;
        if (!join || !fork()) {
            argv[index] = 0;
            return execvp(argv[start], argv+start);
        }
        result = wait(&result) ? WEXITSTATUS(result) : EXIT_FAILURE;
        switch (join[0]) {
            case '&': if (result) return result;
            case '|': if (!result) return EXIT_SUCCESS;
        }
    }
}
