/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#ifndef DECKSELECTOR_H
#define DECKSELECTOR_H

class DeckSelector
{
public:
    enum DeckType { RISK_RICK, RICK_RICK, SHIELDY_RICK };
    DeckType show();
private:
    void printTitle();
    void printOptions(int selected);
};

#endif