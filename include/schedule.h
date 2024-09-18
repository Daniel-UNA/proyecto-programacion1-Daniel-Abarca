#pragma once
#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <ctime>
#include "movie.h"
#include "room.h"

class Schedule {
private:
    struct tm date;
    struct tm startTime;
    struct tm endTime;
    Room** rooms;
    Movie** moviePerRoom;

public:
    Schedule();
    Schedule(const struct tm& inputDate, const struct tm& inputStartTime, const struct tm& inputEndDate,
            int defaultNumOfSeats, int numOfRooms);

    struct tm getDate() const;
    struct tm getStartTime() const;
    struct tm getEndTime() const;
    Movie& getRoomMovie(int roomId);
    Room& getRoom(int roomId);

    void setDate(const struct tm& inputDate);
    void setStartTime(const struct tm& inputStartTime);
    void setEndTime(const struct tm& inputEndDate);
    void setRoomMovie(int roomId, Movie& movieInput);
    

    ~Schedule();

};

#endif