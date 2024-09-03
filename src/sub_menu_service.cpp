#include "sub_menu_service.h"

SubMenuService::SubMenuService(){
    description = "Mantenimiento";
}

SubMenuService::SubMenuService(std::string inputDescription){
    description = inputDescription;
}

std::string SubMenuService::getDescription(){ return description;}

void SubMenuService::setDescription(std::string inputDescription){
    description = inputDescription;
}

void SubMenuService::action(bool* programStatePtr){
    std::cout << "There is nothing here." << std::endl;
    std::getchar();
}

SubMenuService::~SubMenuService(){
    //Good Bye Submenu
}