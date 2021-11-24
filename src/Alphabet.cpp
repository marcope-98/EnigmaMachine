#include "Alphabet.h"

// Costruttori

Alphabet::Alphabet(int size)
{
    this->size = size;

    data = new int[size];
    initIndex = 0;
}

Alphabet::Alphabet(int size, int* data)
{
    this->size = size;
    this->data = data;

    initIndex = 0;
}

Alphabet::Alphabet(const Alphabet& other)
{
    size = other.size;
    initIndex = 0;

    data = new int[size];
    std::copy(other.data, other.data + other.size, data);
}

// Inizializzazione
Alphabet &Alphabet::operator<<=(int val)
{
    data[initIndex] = val;
    initIndex == (size - 1) ? initIndex = 0 : ++initIndex;

    return *this;
}


Alphabet &Alphabet::operator,(int val)
{
    *this <<= val;

    return *this;
}

// default setter
void Alphabet::setAllValuesAt(int value)
{
    for(int i = 0; i < size; ++i)
    {
        data[i] = value;
    }
}


// operatori
//  operatore di accesso (sola lettura)
int Alphabet::operator()(int& i) const
{
    
    return data[i];
}

//  operatore di accesso (lettura + scrittura)
int &Alphabet::operator()(int& i)
{
    int res = reset(i, 0);

    return data[res];
}


//  operatore di step

/*
 * opera tra un Alphabet e un intero
 * ritorna un intero
 * 
 * associa ad un int res il rhs
 * accede all'i-esimo valore del chiamante
*/
int Alphabet::operator>>=(int& i)
{

    int res = i;
    res = this->operator()(res);
    res += i;

    return res;
}

// operatore di step
int Alphabet::operator+(int i)
{
    int res = (*this >>= i);

    return res;
}

// reset 
int Alphabet::reset(int& val, const int& val_)
{
    val < val_         ? val += size : val += 0;
    val >= size + val_ ? val -= size : val -= 0;

    return val - val_;
}


