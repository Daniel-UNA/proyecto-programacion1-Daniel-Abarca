#ifndef SUB_MENU
#define SUB_MENU

#include <iostream>
#include "clear.h"
#include "sub_menu_file.h"

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