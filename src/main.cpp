#include <iostream>
#include "menu.h"
using namespace std;

bool isProgramRunnig;

int main(void){
    Menu *menu = new Menu(2);
    menu->createMenu(0, new SubMenuFile());
    menu->createMenu(1, new SubMenu("Test Menu"));
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