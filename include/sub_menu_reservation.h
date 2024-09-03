#ifndef SUB_MENU_RESERVATION_H
#define SUB_MENU_RESERVATION_H

#include <iostream>
#include "sub_menu.h"

class SubMenuReservation : public SubMenu{
private:
    std::string description;
public:

    SubMenuReservation(std::string inputDescription);
    SubMenuReservation();
    std::string getDescription();
    void setDescription(std::string inputDescription);
    void action(bool* programStatePtr);
    ~SubMenuReservation();
};


#endif