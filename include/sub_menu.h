#pragma once
#ifndef SUB_MENU_H
#define SUB_MENU_H

#include <iostream>
#include "clear.h"
#include "movie.h"
#include "schedule.h"

extern Movie** moviePtr;
extern Schedule** schedulePtr;
extern int* nRoomsPtr;
extern int* nMoviesPtr;
extern int* nSchedulePtr;


class SubMenu {
private:
    std::string description;
public:

    SubMenu(std::string inputDescription);
    SubMenu();
    virtual std::string getDescription();
    virtual void setDescription(std::string inputDescription);
    virtual void action(bool* programStatePtr);
    virtual ~SubMenu();
};


#endif