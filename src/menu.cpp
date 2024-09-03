#include "menu.h"

Menu::Menu(){
    size = 1;
    submenus = new SubMenu*[size];
    for (register int i = 0; i < size; i++){
        submenus[i] = nullptr;
    }
}

Menu::Menu(int iSize){
    size = iSize;
    submenus = new SubMenu*[size];
    for (register int i = 0; i < size; i++){
        submenus[i] = nullptr;
    }
}

void Menu::printMenu(){
    std::cout << "Please select a option:" << std::endl;
    for (register int i = 0; i < size; i++){
        if (submenus[i] != nullptr){
            std::cout << i << ": " << submenus[i]->getDescription() << std::endl;
        }
    }
}

void Menu::action(int actionId, bool* programStatePtr){
    if (submenus[actionId] != nullptr){
        submenus[actionId]->action(programStatePtr);
    }
    
}

void Menu::createMenu(int index, SubMenu* newMenu){
    if (index >= 0 && index < size) {
            submenus[index] = newMenu;
    } else {
            std::cout << "Índice fuera de rango." << std::endl;
    }
}

Menu::~Menu(){
    
    delete[] submenus;
    
}