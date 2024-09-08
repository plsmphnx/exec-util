#include <stdlib.h>
#include <unistd.h>
#include <linux/vt.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[]) {
    return ioctl(0, VT_WAITACTIVE, atoi(argv[1])) || execvp(argv[2], argv+2);
}
