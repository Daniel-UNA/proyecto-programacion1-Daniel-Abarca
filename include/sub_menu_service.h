#pragma once
#ifndef SUB_MENU_SERVICE_H
#define SUB_MENU_SERVICE_H

#include <iostream>
#include "sub_menu.h"


class SubMenuService : public SubMenu{
private:
    std::string description;
    void printMovies();
    void printRooms();
    void printSchedules();
public:

    SubMenuService(std::string inputDescription);
    SubMenuService();
    std::string getDescription();
    void setDescription(std::string inputDescription);
    void action(bool* programStatePtr);
    ~SubMenuService();
};


#endif