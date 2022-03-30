#include <iostream>
#include <windows.h>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");

    char choice;
    while (1) {
        if (personalBudget.isUserLogged() == 0) {
            choice = personalBudget.selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w MENU." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.currentMonthBalance();
                break;
            case '4':
                personalBudget.previousMonthBalance();
                break;
            case '5':
                personalBudget.chosenPeriodBalance();
                break;
            case '6':
                personalBudget.changeLoggedUserPassword();
                break;
            case '7':
                personalBudget.userLogout();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w MENU." << endl << endl;
                system("pause");
                break;
            }
        }
    }
}

