#include "sub_menu_sale.h"

SubMenuSale::SubMenuSale(){
    description = "Venta";
}

void SubMenuSale::submitSale(std::string saleId) {
    int schId;
    int roomId;
    int rowId;
    int colId;
    int userId;
    int inputUID;
    int inputUCreditId;

    schId = std::stoi(getValue(saleId,"sId>"));
    roomId = std::stoi(getValue(saleId,"rId>"));
    rowId = std::stoi(getValue(saleId,"roId>"));
    colId = std::stoi(getValue(saleId,"coId>"));
    userId = std::stoi(getValue(saleId,"uId>"));

    std::cout << "Digite su cedula:";
    std::cin >> inputUID;
    std::cout << std::endl;

    if(inputUID != userId){
        std::cout << "Informacion del consecutivo no concuerda" << std::endl;
        return;
    }

    std::cout << "Digite su tarjeta:";
    std::cin >> inputUCreditId;
    std::cout << std::endl;

    if (inputUCreditId < 1000000) {
        std::cout << "Metodo de pago invalido" << std::endl;
        return;
    }

    schedulePtr[schId]->getRoom(roomId).setSeatState(rowId, colId, 'V');

    std::cout << "Venta realizada correctamente" << std::endl;
}

std::string SubMenuSale::getValue(const std::string &str, const std::string &tag) {
    size_t pos = str.find(tag);
    if (pos == std::string::npos) {
        return " ";
    }
    pos += tag.length();
    size_t endPos = str.find_first_of("|", pos);
    if (endPos == std::string::npos) {
        endPos = str.length();
    }
    return str.substr(pos, endPos - pos);
}

SubMenuSale::SubMenuSale(std::string inputDescription)
{
    description = inputDescription;
}

std::string SubMenuSale::getDescription(){ return description;}

void SubMenuSale::setDescription(std::string inputDescription){
    description = inputDescription;
}

void SubMenuSale::action(bool* programStatePtr){
    bool isRunning = true;
    int option;
    std::string saleId;
    while (isRunning){
        clearScreen();
        option = 0;
        std::cout << description << std::endl <<
                    "1: Pagar" << std::endl <<
                    "2: ..." << std::endl;
        std::cin >> option;

        if(option == 1){
            clearScreen();
            std::cout << "Por Favor Digite el consecutivo:";
            std::cin >> saleId;
            std::cout << std::endl;
            submitSale(saleId);
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