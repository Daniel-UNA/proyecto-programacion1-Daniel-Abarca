#include "sub_menu_reservation.h"

SubMenuReservation::SubMenuReservation(){
    description = "Reserva";
}

void SubMenuReservation::printMovies() {
    for (int i = 0; i < *nMoviesPtr; i++){
        std::cout <<"#" << i << ": " << moviePtr[i]->getName() << std::endl <<
                    "----------------------------------------------------------------------------------------------------" << std::endl <<
                    "|Year: " << moviePtr[i]->getYear() << " |Lenght(min): " << moviePtr[i]->getLength() << " |Country(s): " <<
                    moviePtr[i]->getCountry() << " |Score(0 to 100): " << moviePtr[i]->getReview() << std::endl <<
                    "----------------------------------------------------------------------------------------------------" << std::endl;
        
    }
}

bool SubMenuReservation::checkReservation(int movieId) {
    if (movieId >= *nMoviesPtr){
        std::cout << "Es invalido" << std::endl;
        return false;
    }
    int freeSeats = 0;

    for(int i = 0; i < *nSchedulePtr; i++){
        for(int j = 0; j < *nRoomsPtr; j++){
            if (moviePtr[movieId]->getName() == schedulePtr[i]->getRoomMovie(j).getName()){
                for(int k = 0; k < schedulePtr[i]->getRoom(j).getNumOfSeats();k++){
                    if (schedulePtr[i]->getRoom(j).retSeatState(k / (schedulePtr[i]->getRoom(j).getNumOfSeats() / 2), k % (schedulePtr[i]->getRoom(j).getNumOfSeats() / 2)) == 'L'){
                        freeSeats++;
                    }
                }
            }
        }
    }

    if (freeSeats == 0){
        std::cout << "No hay espacios disponibles o No se proyecta el dia de Hoy." << std::endl;
        return false;
    }
    std::cout << "Hay " << freeSeats << " espacios disponibles." << std::endl;
    return true;
}

void SubMenuReservation::makeReservation(int scheduleId ,int roomId, int row, int col){
    if (schedulePtr[scheduleId]->getRoom(roomId).retSeatState(row, col) != 'L'){
        std::cout << "#No disponible#" << std::endl;
        return;
    }
    int userId = 0;
    std::cout << "Digite su cedula(para indentificar)";
    std::cin >> userId;
    schedulePtr[scheduleId]->getRoom(roomId).setSeatState(row, col, 'R');
    std::cout << "Este es su consecutivo, Por favor copielo!: ";
    std::cout << "sId>" << scheduleId << "|rId>" << roomId << "|roId>" << row << "|coId>" << col << "|uId>" << userId << std::endl;
}

void SubMenuReservation::showRoom(int scheduleId ,int roomId) {
    int option[2];
    std::cout << " C" << std::endl << "F" << std::endl;
    for(int j = 0; j < (schedulePtr[scheduleId]->getRoom(roomId).getNumOfSeats() / 2); j++){
            std::cout << " " << j << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < (schedulePtr[scheduleId]->getRoom(roomId).getNumOfSeats() / 2); i++){
        std::cout << " ";
        for(int j = 0; j < (schedulePtr[scheduleId]->getRoom(roomId).getNumOfSeats() / 2); j++){
            std::cout << "|~|";
        }
        std::cout << std::endl << " ";
        for(int j = 0; j < (schedulePtr[scheduleId]->getRoom(roomId).getNumOfSeats() / 2); j++){
            std::cout << "|" << schedulePtr[scheduleId]->getRoom(roomId).retSeatState(i,j) << "|";
        }
        std::cout << std::endl;
        std::cout << " ";
        for(int j = 0; j < (schedulePtr[scheduleId]->getRoom(roomId).getNumOfSeats() / 2); j++){
            std::cout << "|_|";
        }
        std::cout << std::endl;
    }
    std::cout << "Selecione un Fila(F) y Columna(C) que tenga L:";
    std::cin >> option[0] >> option[1];
    std::cout << std::endl;
    makeReservation(scheduleId, roomId, option[0], option[1]);
}

void SubMenuReservation::showSchedule(int movieId) {
    char dateInFormat[50];
    char timeInFormat[50];
    struct tm tempTime;
    int option[2];
    for(int i = 0; i < *nSchedulePtr; i++){
       for(int j = 0; j < *nRoomsPtr; j++){
            if (moviePtr[movieId]->getName() == schedulePtr[i]->getRoomMovie(j).getName()){
                std::cout << "N#" << i ;
                tempTime = schedulePtr[i]->getDate();
                strftime(dateInFormat, sizeof(dateInFormat),"%d/%m/%Y", &tempTime);
                std::cout << " Date: " << dateInFormat ;
                tempTime = schedulePtr[i]->getStartTime();
                strftime(timeInFormat, sizeof(timeInFormat),"%H:%M", &tempTime);
                std::cout << " From:" << timeInFormat << " To:";
                tempTime = schedulePtr[i]->getEndTime();
                strftime(timeInFormat, sizeof(timeInFormat),"%H:%M", &tempTime);
                std::cout << timeInFormat << std::endl;
                std::cout << "Sala n#: " << j << std::endl;
            }
        }
    }
    std::cout << "Selecione un Horario y Sala(Si no hay solo una disponible):";
    std::cin >> option[0] >> option[1];
    std::cout << std::endl;
    showRoom(option[0], option[1]);
}

SubMenuReservation::SubMenuReservation(std::string inputDescription)
{
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
            int movieOption = 0;
            clearScreen();
            std::cout << "## Peliculas ##" << std::endl;
            printMovies();
            std::cout << "Selecione Pelicula:";
            std::cin >> movieOption;
            std::cout << std::endl;
            if (checkReservation(movieOption)){
                showSchedule(movieOption);
            }
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