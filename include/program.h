#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include "menu.h"

class Program {
private:
    bool isProgramRunnig;
    int option;
    Menu *menu;
public:
    void start();
    void run();
    ~Program();
};

#endif