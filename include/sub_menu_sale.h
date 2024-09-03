#ifndef SUB_MENU_SALE_H
#define SUB_MENU_SALE_H

#include <iostream>
#include "sub_menu.h"

class SubMenuSale : public SubMenu{
private:
    std::string description;
public:

    SubMenuSale(std::string inputDescription);
    SubMenuSale();
    std::string getDescription();
    void setDescription(std::string inputDescription);
    void action(bool* programStatePtr);
    ~SubMenuSale();
};


#endif