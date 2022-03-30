#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>

using namespace std;

class AuxiliaryMethods {
public:
    static int stringToInt(string number);
    static string intToString(int number);
    static float stringToFloat(string number);
    static string readLine();
    static char readCharacter();
    static int loadInteger();
};

#endif
