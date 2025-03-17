/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

extern struct termios orig_termios;

void enableRawMode();
void disableRawMode();
bool keyPressed();
char getKey();

#endif