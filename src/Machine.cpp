#include "Machine.h"


Machine::Machine(Rotor& A, Rotor& B, Rotor& C, Reflector& R, std::string& message): A(A), B(B), C(C), R(R)
{
    this->message = message;

    alphabetFirst = int('a');
    alphabetLast  = int('z');
    alphabetSize = int(alphabetLast - alphabetFirst);
}

void Machine::step(Rotor& A_, Rotor& B_, Rotor& C_)
{
    ++A_;
    if(A_.getOffset() == 0)
    {
        ++B_;
        if(B_.getOffset() == 0)
        {
            ++C_;
        }
    }
}


std::string Machine::encrypt(int offsetA, int offsetB, int offsetC)
{

    Rotor RA(A.getSize(), A.reverse());
    Rotor RB(B.getSize(), B.reverse());
    Rotor RC(C.getSize(), C.reverse());
    A.setOffset(offsetA);
    B.setOffset(offsetB);
    C.setOffset(offsetC);
    RA.setOffset(offsetA);
    RB.setOffset(offsetB);
    RC.setOffset(offsetC);

    int index;
    std::string res;
    for(char i : message)
    {
        index = int(i) - alphabetFirst;
        index = A >>= index;
        index = B >>= index;
        index = C >>= index;
        index = R >>= index;
        index = RC >>= index;
        index = RB >>= index;
        index = RA >>= index;
        //index = RA + (RB + (RC + (R + (C + (B + (A >>= index))))));
//index = A>>=index;
        index < 0            ?  index += alphabetSize + 1 : index += 0;
        index > alphabetSize ?  index -= alphabetSize + 1 : index -= 0;

        //std::cout << index << " " << alphabetSize << std::endl;
        res += index + alphabetFirst;
       step(A,B,C);
       step(RA,RB,RC);
       // std::cout << "-----------------------" << std::endl;
        }


    return res;
}




