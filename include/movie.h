#pragma once
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>

class MOVIE {
private:
    std::string name;
    int year;
    int length;
    std::string country;
    unsigned char review;

public:
    MOVIE();
    MOVIE(std::string inputName, int inputYear, int inputLength, std::string inputCountry, int inputReview);
    std::string getName();
    int getYear();
    int getLength();
    std::string getCountry();
    int getReview();
    void setName(std::string inputName);
    void setYear(int inputYear);
    void setLength(int inputLength);
    void setCountry(std::string inputCountry);
    void setReview(int inputReview);
    ~MOVIE();
};


#endif