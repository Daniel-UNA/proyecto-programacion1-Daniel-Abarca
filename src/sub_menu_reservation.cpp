#include "sub_menu_reservation.h"

SubMenuReservation::SubMenuReservation(){
    description = "Reserva";
}

SubMenuReservation::SubMenuReservation(std::string inputDescription){
    description = inputDescription;
}

std::string SubMenuReservation::getDescription(){ return description;}

void SubMenuReservation::setDescription(std::string inputDescription){
    description = inputDescription;
}

void SubMenuReservation::action(bool* programStatePtr){
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

SubMenuReservation::~SubMenuReservation(){
    //Good Bye Submenu
}