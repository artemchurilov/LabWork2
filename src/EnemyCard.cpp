/* Artem Churilov st130184@student.spbu.ru
    LabWork 2 task "Making Game" step 4 "Create Simple Game Engine"
*/

#include "EnemyCard.h"

EnemyCard::EnemyCard(int p) : priority(p) {}

int EnemyCard::getPriority() const
{
    return priority;
}