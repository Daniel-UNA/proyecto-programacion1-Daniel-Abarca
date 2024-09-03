#ifndef SUB_MENU_FILE
#define SUB_MENU_FILE

#include <iostream>
#include "sub_menu.h"

class SubMenuFile : public SubMenu {
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