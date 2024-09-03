#ifndef MENU_H
#define MENU_H

#include "sub_menu_file.h"
#include "sub_menu_service.h"
#include "sub_menu_reservation.h"
#include "sub_menu_sale.h"
#include <iostream>

class Menu {
private:
    SubMenu** submenus;
    int size;

public:
    Menu();
    Menu(int iSize);
    void printMenu();
    void action(int actionId, bool* programStatePtr);
    void createMenu(int index, SubMenu* newMenu);
    ~Menu();
};


#endif