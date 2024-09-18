#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include "menu.h"
#include "room.h"
#include "movie.h"
#include "schedule.h"



class Program {
private:
    bool isProgramRunnig;
    int option;
    int numOfRooms;
    int numOfMovies;
    int numOfSchedules;
    int defaultNumOfSeatsPerRoom;
    struct tm startTime;
    struct tm today;
    time_t nowTime;
    Menu *menu;
    Movie** movies;
    Schedule** schedules;
public:
    void start();
    void initializeMovies();
    void initializeSchedules();
    void run();
    ~Program();
};

#endif