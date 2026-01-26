#include "keyboard.h"
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdio.h>

static struct termios oldt;

// Enable RAW mode
void init_keyboard() {
    struct termios newt;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO); // Disable buffering & echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

// Restore terminal
void close_keyboard() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

// Non-blocking key check
int kbhit() {
    struct timeval tv = {0, 0};
    fd_set fds;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
}

// Get character
int getch_posix() {
    return getchar();
}
