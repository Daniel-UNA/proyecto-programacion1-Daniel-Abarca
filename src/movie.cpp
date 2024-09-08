#include "movie.h"


Movie::Movie() {
    name = "NONE";
    year = 1900;
    country = "NONE";
    length = 120;
    review = 1;

}

Movie::Movie(std::string inputName, int inputYear, int inputLength, std::string inputCountry, int inputReview) {
    name = inputName;
    year = inputYear;
    country = inputCountry;
    length = inputLength;

    if((inputReview < UCHAR_MAX) && (inputReview > 0)) {
        review = (unsigned char)inputReview;
        return;
    }
    review = 1;
    std::cout << "Fuera de rango. Usando variable predeterminada." << std::endl;
}

std::string Movie::getName() { return name; }

int Movie::getYear() { return year; }

int Movie::getLength() { return length; }

std::string Movie::getCountry() { return country; }

int Movie::getReview() { return (int)review; }


void Movie::setName(std::string inputName) {
    name = inputName;
}

void Movie::setYear(int inputYear) {
    year = inputYear;
}

void Movie::setLength(int inputLength){
    length = inputLength;
}

void Movie::setCountry(std::string inputCountry) {
    country = inputCountry;
}

void Movie::setReview(int inputReview) {
    if((inputReview < UCHAR_MAX) && (inputReview > 0)) {
        review = (unsigned char)inputReview;
        return;
    }
    review = 1;

    std::cout << "Fuera de rango. Usando variable predeterminada." << std::endl;
}

Movie::~Movie() {
    //Movie has gone.
}
