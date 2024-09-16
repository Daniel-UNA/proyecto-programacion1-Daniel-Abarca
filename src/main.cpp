#include "program.h"

int main(void){
    Program program;
    program.start();
    program.run();
    program.~Program();
    return 0;
}