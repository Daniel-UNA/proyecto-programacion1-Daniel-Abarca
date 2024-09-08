#pragma once
#ifndef SUB_MENU_H
#define SUB_MENU_H

#include <iostream>
#include "clear.h"


class SubMenu {
private:
    std::string description;
public:

    SubMenu(std::string inputDescription);
    SubMenu();
    virtual std::string getDescription();
    virtual void setDescription(std::string inputDescription);
    virtual void action(bool* programStatePtr);
    virtual ~SubMenu();
};


#endif