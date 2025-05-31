
/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "../include/InputSystem.h"
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include <cstdlib>
#include <string>



// Initialize static members
struct termios InputSystem::orig_termios;
bool InputSystem::raw_mode_enabled = false;
/**
 * @brief Enables raw mode by modifying terminal flags.
 * @details
 * - Saves original terminal settings.
 * - Disables line buffering (ICANON) and input echo (ECHO).
 */
void InputSystem::enableRawMode()
{
    if (raw_mode_enabled) return;
    if (tcgetattr(STDIN_FILENO, &orig_termios) == -1) {
        perror("tcgetattr");
        return;
    }
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);
        if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1) {
        perror("tcsetattr");
    } else {
        raw_mode_enabled = true;
    }

}
/**
 * @brief Restores the terminal to its original state.
 */
void InputSystem::disableRawMode()
{
    if (!raw_mode_enabled) return;
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1) {
        perror("tcsetattr");
    } else {
        raw_mode_enabled = false; // Сбрасываем флаг
    }
}

/**
 * @brief Checks for pending input using `select()`.
 * @return true if a key is pressed, false otherwise.
 * @note Uses non-blocking I/O to check for input.
 */
bool InputSystem::keyPressed()
{
    struct timeval tv = {0, 0};
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO+1, &fds, NULL, NULL, &tv) == 1;

}
/**
 * @brief Reads a single character from stdin.
 * @return Pressed character (0 if no input).
 * @warning Blocks if `keyPressed()` is not used to check for input first.
 */
char InputSystem::getKey()
{
    char c = 0;
    if(read(STDIN_FILENO, &c, 1) < 0) perror("read");
    return c;
}