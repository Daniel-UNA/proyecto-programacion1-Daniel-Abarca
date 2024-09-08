#pragma once
#ifndef SUB_MENU_FILE_H
#define SUB_MENU_FILE_H

#include <iostream>
#include "sub_menu.h"


class SubMenuFile : public SubMenu{
private:
    std::string description;
public:

    SubMenuFile();
    SubMenuFile(std::string inputDescription);
    std::string getDescription();
    void setDescription(std::string inputDescription);
    void action(bool* programStatePtr);
    ~SubMenuFile();
};


#endif