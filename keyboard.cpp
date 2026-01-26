#include "keyboard.h"

#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdio.h>

int kbhit() {
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

int getch_posix() {
    struct termios oldt, newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    int c = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return c;
}
