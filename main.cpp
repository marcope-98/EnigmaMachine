#include <iostream>
#include <string>
#include "Machine.h"
#include <fstream>

using namespace std;

int main() {

    int n = 26;
    Rotor A(n);
   // A <<= 1, 2, 4, -1, -4, -1, -1, 0;
    A <<= 10, 22, 19, 9, -2, 8, 8, 8, -1, 7, 7, 7, 13, 11, -6, -6, -16, -14, -7, -15, -14, 1, -21, -3, -19, -6;

    Rotor B(n);
   // B <<= 5, 0, 2, -3, 2, -3, 1, -4;
   B <<= 10, 22, 19, 9, -2, 8, 8, 8, -1, 7, 7, 7, 13, 11, -6, -6, -16, -14, -7, -15, -14, 1, -21, -3, -19, -6;

    Rotor C(n);
    //C <<= 5, 2, 2, -3, -3, 1, -4, 0;
   C <<= 10, 22, 19, 9, -2, 8, 8, 8, -1, 7, 7, 7, 13, 11, -6, -6, -16, -14, -7, -15, -14, 1, -21, -3, -19, -6;

    Reflector R(n);
    //R <<= 7, 4, 4, 1, -1, -4, -4, -7;
    R.standardReflector();

    string boh ("abcdefghijklmnopqrstuvwxyz");
//    string boh("e");
    ofstream file("test.txt");
    Machine test(A,B,C,R,boh);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j<n; ++j)
            for (int k = 0; k < n; ++k)
            {
                //std::cout << test.encrypt(i, j, k) << std::endl;
                file << test.encrypt(i, j, k) << std::endl;
            }
    file.close();

    std::ifstream fileread("test.txt");
    std::string str;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
            {
                std::getline(fileread, str);
    
        Machine test2(A, B, C, R, str);
        //std::cout << str << std::endl;
        std::cout << test2.encrypt(i, j, k) << std::endl;
                    
    }
    return 0;
}
