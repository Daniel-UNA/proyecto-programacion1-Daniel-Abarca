#include <iostream>
#include "menu.h"
using namespace std;

bool isProgramRunnig;

int main(void){
    Menu *menu = new Menu(4);
    menu->createMenu(0, new SubMenuFile());
    menu->createMenu(1, new SubMenuService());
    menu->createMenu(2, new SubMenuReservation());
    menu->createMenu(3, new SubMenuSale());
    int option;
    isProgramRunnig = true;

    while (isProgramRunnig){
        option = 0;
        menu->printMenu();
        scanf("%d",&option);
        menu->action(option,&isProgramRunnig);
        clearScreen();
    }
    
    menu->~Menu();

    return 0;
}