#ifndef USERSFILE_H
#define USERSFILE_H
#include <iostream>
#include <vector>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"
#include "Markup.h"

using namespace std;

class UsersFile: public XMLFile{

public:
    UsersFile(string usersFileName) : XMLFile(usersFileName){};

    void addUserToFile(User user);
    vector<User>readUsersFromFile();
    void saveAllUsersToFile(vector<User>&users);
};

#endif
