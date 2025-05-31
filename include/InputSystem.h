/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/
#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include <termios.h>


/**
 * @class InputSystem
 * @brief Handles low-level terminal input in raw mode.
 * @details Provides static methods to enable/disable raw input and read keystrokes without echo.
 */
class InputSystem
{
public:
    /**
     * @brief Enables raw terminal input mode.
     * @details Disables canonical mode (line buffering) and echo.
     */
    static void enableRawMode();

    /**
     * @brief Restores the terminal to its original settings.
     */
    static void disableRawMode();

    /**
     * @brief Checks if a key has been pressed.
     * @return true if a key is pressed, false otherwise.
     */
    static bool keyPressed();

    /**
     * @brief Reads a single keystroke from the terminal.
     * @return The ASCII character of the pressed key.
     */
    static char getKey();

    static char getKeyInternal();
private:
    static struct termios orig_termios; ///< Original terminal settings to restore later.
    static bool raw_mode_enabled;
};

#endif