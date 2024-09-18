#pragma once
#ifndef ROOM_H
#define ROOM_H


class Room {
private:

    int roomId;
    int numOfSeats;
    int price;
    char** seats;

public:

    Room();
    Room(int intputRoomId, int inputNumOfSeats, int inputPrice);

    int getRoomId();
    int getNumOfSeats();
    int getPrice();
    char retSeatState(int seatRow, int seatColums);
    void setSeatState(int seatRow, int seatColums, char state);
    void setRoomId(int inputRoomId);
    void setNumOfSeats(int inputNumOfSeats);
    void setPrice(int inputPrice);

    ~Room();

};



#endif