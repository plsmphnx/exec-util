#include <stdlib.h>
#include <unistd.h>
#include "util/execw.c"

void main(int argc, char *argv[]) {
    while (1) execw(argv[1], argv+1);
}
