#include "room.h"

Room::Room() {
    roomId = 0;
    numOfSeats = 0;
    price = 0;
}

Room::Room(int intputRoomId, int inputNumOfSeats, int inputPrice) {
    roomId = intputRoomId;
    numOfSeats = inputNumOfSeats;
    price = inputPrice;
}

int Room::getRoomId() { return roomId; }

int Room::getNumOfSeats() { return numOfSeats; }

int Room::getPrice() { return price; }

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
