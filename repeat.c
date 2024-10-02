#include <stdlib.h>
#include <unistd.h>
#include "util/execw.c"

void main(int argc, char *argv[]) {
    char join = argv[1][0], always = join == ';', success = join == '&';
    while (!execw(argv[2], argv+2) == success || always);
}
