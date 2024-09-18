#include "sub_menu_service.h"




SubMenuService::SubMenuService(){
    description = "Mantenimiento";

}

void SubMenuService::printMovies() {
    for (int i = 0; i < *nMoviesPtr; i++){
        std::cout << moviePtr[i]->getName() << std::endl <<
                    "----------------------------------------------------------------------------------------------------" << std::endl <<
                    "|Year: " << moviePtr[i]->getYear() << " |Lenght(min): " << moviePtr[i]->getLength() << " |Country(s): " <<
                    moviePtr[i]->getCountry() << " |Score(0 to 100): " << moviePtr[i]->getReview() << std::endl <<
                    "----------------------------------------------------------------------------------------------------" << std::endl;
        
    }
}

void SubMenuService::printRooms() {
    for (int i = 0; i < *nRoomsPtr; i++){
        std::cout << "ID: " << schedulePtr[0]->getRoom(i).getRoomId() <<
        " |Number Of Seats: " << schedulePtr[0]->getRoom(i).getNumOfSeats() <<
        " |Price: #Los precios son por Horario." << std::endl;
    }
}

void SubMenuService::printSchedules() {
    char dateInFormat[50];
    char timeInFormat[50];
    struct tm tempTime;
    for (int i = 0; i < *nSchedulePtr; i++){
        tempTime = schedulePtr[i]->getDate();
        strftime(dateInFormat, sizeof(dateInFormat),"%d/%m/%Y", &tempTime);
        std::cout << "Date: " << dateInFormat ;
        tempTime = schedulePtr[i]->getStartTime();
        strftime(timeInFormat, sizeof(timeInFormat),"%H:%M", &tempTime);
        std::cout << " From:" << timeInFormat << " To:";
        tempTime = schedulePtr[i]->getEndTime();
        strftime(timeInFormat, sizeof(timeInFormat),"%H:%M", &tempTime);
        std::cout << timeInFormat << std::endl;
        std::cout << "  Room Prices:" << std::endl;
        for(int j = 0; j < *nRoomsPtr; j++){
            std::cout << "Room#" << j << ": " << schedulePtr[i]->getRoom(j).getPrice() << " Colones" << std::endl; 
        }
    }
}

SubMenuService::SubMenuService(std::string inputDescription)
{
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
            std::cout << "## Peliculas ##" << std::endl;
            printMovies();
            getchar();
        }

        if(option == 2){
            clearScreen();
            std::cout << "## Salas ##" << std::endl;
            printRooms();
            getchar();
        }

        if(option == 3){
            clearScreen();
            std::cout << "## Horarios ##" << std::endl;
            printSchedules();
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