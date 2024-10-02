static inline int execw(const char *file, char *const argv[]) {
    int status;
    return fork()
        ? wait(&status) ? WEXITSTATUS(status) : EXIT_FAILURE
        : execvp(file, argv);
}
