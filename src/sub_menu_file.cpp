#include "sub_menu_file.h"

SubMenuFile::SubMenuFile(){
    description = "Archivo";
}

SubMenuFile::SubMenuFile(std::string inputDescription){
    description = inputDescription;
}

std::string SubMenuFile::getDescription(){ return description;}

void SubMenuFile::setDescription(std::string inputDescription){
    description = inputDescription;
}

void SubMenuFile::action(bool* programStatePtr){
    bool isRunning = true;
    int option;
    while (isRunning){
        clearScreen();
        option = 0;
        std::cout << description << std::endl <<
                    "1: Acerca de" << std::endl <<
                    "2: Salir del programa" << std::endl <<
                    "3:.." << std::endl;
        std::cin >> option;
        

        if (option == 1){
            clearScreen();
            std::cout << "Programa creado por Daniel Abarca." << std::endl;
            getchar();
        }

        if (option == 2){
            isRunning = false;
            *programStatePtr = false;
        }

        if (option == 3){ isRunning = false; }

        std::cin.clear();
        std::cin.ignore();
    }
}

SubMenuFile::~SubMenuFile(){
    //Good Bye Submenu
}