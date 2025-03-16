#include "EnemyCard.h"

EnemyCard::EnemyCard(int p) : priority(p) {}

int EnemyCard::getPriority() const
{
    return priority;
}