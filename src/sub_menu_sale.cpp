#include "sub_menu_sale.h"

SubMenuSale::SubMenuSale(){
    description = "Venta";
}

SubMenuSale::SubMenuSale(std::string inputDescription){
    description = inputDescription;
}

std::string SubMenuSale::getDescription(){ return description;}

void SubMenuSale::setDescription(std::string inputDescription){
    description = inputDescription;
}

void SubMenuSale::action(bool* programStatePtr){
    bool isRunning = true;
    int option;
    while (isRunning){
        clearScreen();
        option = 0;
        std::cout << description << std::endl <<
                    "1: Peliculas" << std::endl <<
                    "2: ..." << std::endl;
        std::cin >> option;

        if(option == 1){
            clearScreen();
            std::cout << "## Work In Progress ##" << std::endl;
            getchar();
        }

        if(option == 2){ isRunning = false; }
        
        std::cin.clear();
        std::cin.ignore();
    }
}

SubMenuSale::~SubMenuSale(){
    //Good Bye Submenu
}