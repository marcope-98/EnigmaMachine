#ifndef ENIGMA_REFLECTOR_H
#define ENIGMA_REFLECTOR_H
#include "Alphabet.h"

class Reflector : public Alphabet
{

public:
    explicit Reflector(int size) : Alphabet(size) {}
    void standardReflector();

};


#endif //ENIGMA_REFLECTOR_H
