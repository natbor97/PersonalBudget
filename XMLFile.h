#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"

using namespace std;

class XMLFile {
    const string FILE_NAME;

public:
    XMLFile(string fileName) : FILE_NAME(fileName) {}

    string getFileName();
};

#endif
