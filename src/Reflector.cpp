#include "Reflector.h"

void Reflector::standardReflector()
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = (size - 1) - i*2;
    }
}
