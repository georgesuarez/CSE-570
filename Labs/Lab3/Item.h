#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
  public:
    Item(std::string &production, int dotPos) : production(production), dotPos(dotPos){};

    std::string getProduction();
    int getDotPos();

    bool operator==(const Item &) const;
    bool operator<(const Item &) const;

  private:
    std::string production;
    int dotPos;
};

#endif // ITEM_H
