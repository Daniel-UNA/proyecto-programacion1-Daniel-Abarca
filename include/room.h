#pragma once
#ifndef ROOM_H
#define ROOM_H


class Room {
private:

    int roomId;
    int numOfSeats;
    int price;
    

public:

    Room();
    Room(int intputRoomId, int inputNumOfSeats, int inputPrice);
    int getRoomId();
    int getNumOfSeats();
    int getPrice();
    void setRoomId(int inputRoomId);
    void setNumOfSeats(int inputNumOfSeats);
    void setPrice(int inputPrice);

};



#endif