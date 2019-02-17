#include "Item.h"
#include <string>

std::string Item::getProduction()
{
    return production;
}

int Item::getDotPos()
{
    return dotPos;
}

bool Item::operator==(const Item& other) const
{
    return other.production == production;
}

bool Item::operator<(const Item& other) const
{
    return other.production > production;
}
