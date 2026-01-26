#ifndef KEYBOARD_H
#define KEYBOARD_H

void init_keyboard();
void close_keyboard();

int kbhit();
int getch_posix();

#endif
