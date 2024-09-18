#include "program.h"

int main(void){

    try
    {
        Program program;
        program.start();
        program.initializeMovies();
        program.initializeSchedules();
        program.run();
        program.~Program();
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;

}