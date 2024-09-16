#include "room.h"

Room::Room() {
    roomId = 0;
    numOfSeats = 20;
    price = 0;
    seats = new char[numOfSeats];
    for (int i = 0; i < numOfSeats; i++){
        seats[i] = 'L';
    }
}

Room::Room(int intputRoomId, int inputNumOfSeats, int inputPrice) {
    roomId = intputRoomId;
    numOfSeats = inputNumOfSeats;
    price = inputPrice;
    seats = new char[numOfSeats];
    for (int i = 0; i < numOfSeats; i++){
        seats[i] = 'L';
    }
}

int Room::getRoomId() { return roomId; }

int Room::getNumOfSeats() { return numOfSeats; }

int Room::getPrice() { return price; }

char Room::retSeatState(int seatId) { return seats[seatId]; }

void Room::setSeatState(int seatID, char state) {
    seats[seatID] = state;
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
