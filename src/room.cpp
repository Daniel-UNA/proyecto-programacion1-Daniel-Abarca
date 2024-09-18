#include "room.h"

Room::Room() {
    roomId = 0;
    numOfSeats = 20;
    price = 0;
    seats = new char*[numOfSeats/2];
    for (int i = 0; i < numOfSeats/2; i++){
        seats[i] = new char[numOfSeats/2];
    }

    for (int i = 0; i < numOfSeats/2; i++){
        for(int j = 0; j <numOfSeats/2; j++){
            seats[i][j] = 'L';
        }
    }
}

Room::Room(int intputRoomId, int inputNumOfSeats, int inputPrice) {
    roomId = intputRoomId;
    numOfSeats = inputNumOfSeats;
    price = inputPrice;
    seats = new char*[numOfSeats/2];
    for (int i = 0; i < numOfSeats/2; i++){
        seats[i] = new char[numOfSeats/2];
    }

    for (int i = 0; i < numOfSeats/2; i++){
        for(int j = 0; j <numOfSeats/2; j++){
            seats[i][j] = 'L';
        }
    }
}

int Room::getRoomId() { return roomId; }

int Room::getNumOfSeats() { return numOfSeats; }

int Room::getPrice() { return price; }

char Room::retSeatState(int seatRow, int seatColums) { return seats[seatRow][seatColums]; }

void Room::setSeatState(int seatRow, int seatColums, char state) {
    seats[seatRow][seatColums] = state;
}

void Room::setRoomId(int inputRoomId) {
    roomId = inputRoomId;
}

void Room::setNumOfSeats(int inputNumOfSeats) {
    numOfSeats = inputNumOfSeats;
}

void Room::setPrice(int inputPrice) {
    price = inputPrice;
}

Room::~Room() {
    //GoodBye Room
}
