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
    bool isRunning = true;
    int option;
    while (isRunning){
        clearScreen();
        option = 0;
        std::cout << description << std::endl <<
                    "1: Peliculas" << std::endl <<
                    "2: Salas" << std::endl <<
                    "3: Horarios" << std::endl <<
                    "4: ..." << std::endl;
        std::cin >> option;

        if(option == 1){
            clearScreen();
            std::cout << "## Work In Progress ##" << std::endl;
            getchar();
        }

        if(option == 2){
            clearScreen();
            std::cout << "## Work In Progress ##" << std::endl;
            getchar();
        }

        if(option == 3){
            clearScreen();
            std::cout << "## Work In Progress ##" << std::endl;
            getchar();
        }

        if(option == 4){ isRunning = false; }
        
        std::cin.clear();
        std::cin.ignore();
    }
}

SubMenuService::~SubMenuService(){
    //Good Bye Submenu
}