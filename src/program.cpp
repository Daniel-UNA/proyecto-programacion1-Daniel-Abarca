#include "program.h"

using namespace std;

void Program::start() {
    menu = new Menu(4);
    menu->createMenu(0, new SubMenuFile());
    menu->createMenu(1, new SubMenuService());
    menu->createMenu(2, new SubMenuReservation());
    menu->createMenu(3, new SubMenuSale());
    isProgramRunnig = true;
}

void Program::run() {
    while (isProgramRunnig){
        option = 0;
        menu->printMenu();
        scanf("%d",&option);
        menu->action(option,&isProgramRunnig);
        clearScreen();
    }
}

Program::~Program() {
    menu->~Menu();
}
