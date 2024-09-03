#ifndef SUB_MENU_SERVICE
#define SUB_MENU_SERVICE

#include <iostream>
#include "sub_menu.h"

class SubMenuService : public SubMenu{
private:
    std::string description;
public:

    SubMenuService(std::string inputDescription);
    SubMenuService();
    std::string getDescription();
    void setDescription(std::string inputDescription);
    void action(bool* programStatePtr);
    ~SubMenuService();
};


#endif