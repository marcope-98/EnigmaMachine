#include "Rotor.h"

Rotor::Rotor(int size) : Alphabet(size)
{
    offset = 0;
}

Rotor::Rotor(int size, int* data) : Alphabet(size, data)
{
    offset = 0;
}

Rotor &Rotor::operator++()
{
    ++offset;

    if (offset == size)
    {
        offset = 0;
    }
    return *this;
}


int Rotor::operator()(int& i) const
{
    //int res = reset(i, offset);
    
    return data[i];

}

int &Rotor::operator()(int& i)
{
    //std::cout << "access" << std::endl;
    int res = reset(i, offset);

    return data[res];
}

int* Rotor::reverse() const
{
    int* res = new int[size];
    int tmp;
    for ( int i = 0; i <size; ++i )
    {
        tmp = data[i] + i;
        res[tmp] = -data[i];
    }
    return res;
}



int Rotor::operator>>=(int& i)
{

    int res = i;
    res = this->operator()(i);
    res += i;


    return res;
}

int Rotor::operator+(int i)
{
    int res = (*this >>= i);


    return res;
}







