#include "sub_menu.h"

SubMenu::SubMenu(){
    description = "This is a Submenu";
}

SubMenu::SubMenu(std::string inputDescription){
    description = inputDescription;
}

std::string SubMenu::getDescription(){ return description;}

void SubMenu::setDescription(std::string inputDescription){
    description = inputDescription;
}

void SubMenu::action(bool* programStatePtr){
    std::cout << "There is nothing here." << std::endl;
    std::getchar();
}

SubMenu::~SubMenu(){
    //Good Bye Submenu
}