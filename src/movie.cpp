#include "movie.h"


MOVIE::MOVIE() {
    name = "NONE";
    year = 1900;
    country = "NONE";
    length = 120;
    review = 1;

}

MOVIE::MOVIE(std::string inputName, int inputYear, int inputLength, std::string inputCountry, int inputReview) {
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

std::string MOVIE::getName() { return name; }

int MOVIE::getYear() { return year; }

int MOVIE::getLength() { return length; }

std::string MOVIE::getCountry() { return country; }

int MOVIE::getReview() { return (int)review; }


void MOVIE::setName(std::string inputName) {
    name = inputName;
}

void MOVIE::setYear(int inputYear) {
    year = inputYear;
}

void MOVIE::setLength(int inputLength){
    length = inputLength;
}

void MOVIE::setCountry(std::string inputCountry) {
    country = inputCountry;
}

void MOVIE::setReview(int inputReview) {
    if((inputReview < UCHAR_MAX) && (inputReview > 0)) {
        review = (unsigned char)inputReview;
        return;
    }
    review = 1;

    std::cout << "Fuera de rango. Usando variable predeterminada." << std::endl;
}

MOVIE::~MOVIE() {
    //Movie has gone.
}
