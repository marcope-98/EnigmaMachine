#ifndef ENIGMA_MACHINE_H
#define ENIGMA_MACHINE_H

#include "Rotor.h"
#include "Reflector.h"
#include <string>
#include <iostream>
#include <cmath>

class Machine
{
private:
    Rotor A;
    Rotor B;
    Rotor C;
    Reflector R;

    std::string message;
    int alphabetSize;
    int alphabetFirst;
    int alphabetLast;


    void step(Rotor& A_, Rotor& B_, Rotor& C_);


public:
    Machine(Rotor& A, Rotor& B, Rotor& C, Reflector& R, std::string& message);

    std::string encrypt(int offsetA, int offsetB, int offsetC);
};


#endif //ENIGMA_MACHINE_H
