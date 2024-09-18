#include "schedule.h"



Schedule::Schedule() {
    time_t now = time(0);
    date = *localtime(&now);
    rooms = new Room*[1];
    moviePerRoom = new Movie*[1];

    startTime = {};
    startTime.tm_hour = 0;
    startTime.tm_min = 0;
    startTime.tm_sec = 0;

    endTime = {};
    endTime.tm_hour = 0;
    endTime.tm_min = 0;
    endTime.tm_sec = 0;

    mktime(&date);
    mktime(&startTime);
    mktime(&endTime);

    for (int i = 0; i < 1; i++){
        rooms[i] = new Room(i, 10, 0);
        moviePerRoom[i] = nullptr;
    }

}

Schedule::Schedule(const tm &inputDate, const tm &inputStartTime, const tm &inputEndDate, 
                    int defaultNumOfSeats, int numOfRooms) : date(inputDate), startTime(inputStartTime), endTime(inputEndDate) {
    rooms = new Room*[numOfRooms];
    moviePerRoom = new Movie*[numOfRooms];
    for (int i = 0; i < numOfRooms; i++){
        rooms[i] = new Room(i, defaultNumOfSeats, ((int)((long int)rand() + 1500) % 10000));
        moviePerRoom[i] = nullptr;
    }
    mktime(&date);
    mktime(&startTime);
    mktime(&endTime);
}

tm Schedule::getDate() const { return date; }

tm Schedule::getStartTime() const { return startTime; }

tm Schedule::getEndTime() const { return endTime; }

Movie &Schedule::getRoomMovie(int roomId) { return* moviePerRoom[roomId]; }

Room &Schedule::getRoom(int roomId){ return* rooms[roomId]; }

void Schedule::setDate(const tm &inputDate){
    date = inputDate;
    mktime(&date);
}

void Schedule::setStartTime(const tm &inputStartTime) {
    startTime = inputStartTime;
    mktime(&startTime);
}

void Schedule::setEndTime(const tm &inputEndDate) {
    endTime = inputEndDate;
    mktime(&endTime);
}

void Schedule::setRoomMovie(int roomId, Movie& movieInput) {
    moviePerRoom[roomId] = &movieInput;
}

Schedule::~Schedule() {
    delete[] rooms;
    delete[] moviePerRoom;
}
