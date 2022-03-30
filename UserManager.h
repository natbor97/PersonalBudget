#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager{
    int loggedUserId;
    vector<User>users;
    UsersFile usersFile;

    User insertNewUsersData();
    int getNewUserId();
    bool loginExists(string login);

public:
    UserManager(string usersFileName) : usersFile(usersFileName){
        loggedUserId=0;
        users=usersFile.readUsersFromFile();
    }

    void userRegistration();
    int getLoggedUserId();
    int userLogin();
    bool isUserLogged();
    void changeLoggedUserPassword();
    void userLogout();
    void saveAllUsersToFile();
    char selectOptionFromMainMenu();
	char selectOptionFromUserMenu();
};

#endif
