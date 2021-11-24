#ifndef ENIGMA_ROTOR_H
#define ENIGMA_ROTOR_H

#include <iostream>
#include <Alphabet.h>


class Rotor : public Alphabet
{
private:
    int offset;

public:
    explicit Rotor(int size);
    Rotor(int size, int* data);

    int getOffset() const { return offset; }
    void setOffset(int i) { offset = i; }


    Rotor &operator++();
    int operator()(int& i) const override;
    int &operator()(int& i) override;
    int operator>>=(int& i) override;
    int operator+(int i) override;




    int* reverse() const;

};




#endif //ENIGMA_ROTOR_H
