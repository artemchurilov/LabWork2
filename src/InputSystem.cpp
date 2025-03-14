
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "InputSystem.h"
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/select.h>
#include <cstdlib>
#include <string>
struct termios orig_termios; // Определение переменной

void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &orig_termios);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

bool keyPressed()
{
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO+1, &fds, NULL, NULL, &tv) == 1;

}

char getKey()
{
    char c = 0;
    if(read(STDIN_FILENO, &c, 1) < 0) perror("read");
    return c;
}