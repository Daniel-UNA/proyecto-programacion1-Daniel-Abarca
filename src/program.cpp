#include "program.h"

Movie** moviePtr;
Schedule** schedulePtr;
int* nRoomsPtr;
int* nMoviesPtr;
int* nSchedulePtr;



using namespace std;

void Program::start() {
    menu = new Menu(4);
    menu->createMenu(0, new SubMenuFile());
    menu->createMenu(1, new SubMenuService());
    menu->createMenu(2, new SubMenuReservation());
    menu->createMenu(3, new SubMenuSale());
    srand((time(0) % 10000) * ((time(0) >> 10) % 100000000));
    numOfRooms = 3;
    numOfMovies = 5;
    numOfSchedules = 4;
    nRoomsPtr = &numOfRooms;
    nMoviesPtr = &numOfMovies;
    nSchedulePtr = &numOfSchedules;
    defaultNumOfSeatsPerRoom = 40;
    nowTime = time(0);
    today = *localtime(&nowTime);
    startTime = {};
    startTime.tm_mday = today.tm_mday;
    startTime.tm_mon = today.tm_mon;
    startTime.tm_year = today.tm_year;
    startTime.tm_hour = 8;
    startTime.tm_min = 30;
    startTime.tm_sec = 0;
    movies = new Movie*[numOfMovies];
    schedules = new Schedule*[numOfSchedules];
    
    isProgramRunnig = true;
    
    
    for (int i = 0; i < numOfSchedules; i++){
        schedules[i] = new Schedule(today, startTime, startTime , defaultNumOfSeatsPerRoom , numOfRooms);
    }
}

void Program::initializeMovies() {
    movies[0] = new Movie("King Kong (2005 film)", 2005, 192,"Nueva Zelanda, USA", 72);
    movies[1] = new Movie("Shrek", 2001, 90,"USA", 79);
    movies[2] = new Movie("Godzilla (2014 film)", 2014, 122,"Japon, USA", 64);
    movies[3] = new Movie("Godzilla x Kong: The New Empire", 2024, 115,"Australia, USA", 61);
    movies[4] = new Movie("Gojira -1.0(Godzilla Minus One)", 2023, 124,"Japon", 77);
}

void Program::initializeSchedules() {
    int* moviePerRoom = new int[numOfRooms];
    int minOfLongestMovie = 0;
    struct tm newStartTime = startTime;
    struct tm newEndTime = {};
    moviePerRoom[-1] = -1;
    

    for (int i = 0; i < numOfSchedules; i++){
        newStartTime.tm_min += ((minOfLongestMovie + 30) % 60);
        newStartTime.tm_hour += ((minOfLongestMovie + 30) / 60);
        schedules[i]->setStartTime(newStartTime);

        for(int j = 0; j < numOfRooms; j++){
            do {
                moviePerRoom[j] = rand() % numOfMovies;
            } while (moviePerRoom[j] == moviePerRoom[j - 1]);

            schedules[i]->setRoomMovie(j, *movies[moviePerRoom[j]]);

            if (movies[moviePerRoom[j]]->getLength() > minOfLongestMovie){
                minOfLongestMovie = movies[moviePerRoom[j]]->getLength();
            }
        }

        newEndTime = newStartTime;
        newEndTime.tm_min += minOfLongestMovie % 60;
        newEndTime.tm_hour += minOfLongestMovie / 60;

        schedules[i]->setEndTime(newEndTime);
    }
}

void Program::run() {
    moviePtr = movies;
    schedulePtr = schedules;
    while (isProgramRunnig){
        option = 0;
        menu->printMenu();
        scanf("%d",&option);
        menu->action(option,&isProgramRunnig);
        clearScreen();
    }
}

Program::~Program() {
    delete menu;
    delete[] movies;
    delete[] schedules;
}
