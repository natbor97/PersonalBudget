#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include "UserManager.h"
#include "ExpensesAndIncomesManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    ExpensesAndIncomesManager* expensesAndIncomesManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    PersonalBudget(string usersFileName, string incomesFileName, string expensesFileName) :
        userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
        expensesAndIncomesManager=NULL;
    };

    ~PersonalBudget() {
        delete expensesAndIncomesManager;
        expensesAndIncomesManager=NULL;
    }

    void userRegistration();
    int getLoggedUserId();
    void userLogin();
    bool isUserLogged();
    void changeLoggedUserPassword();
    void userLogout();
    void addIncome();
    void addExpense();
    void currentMonthBalance();
    void previousMonthBalance();
    void chosenPeriodBalance();

    char selectOptionFromMainMenu();
	char selectOptionFromUserMenu();
};


#endif
