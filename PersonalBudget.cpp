#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

int PersonalBudget::getLoggedUserId() {
    return userManager.getLoggedUserId();
}

void PersonalBudget::userLogin() {
    userManager.userLogin();

    if(userManager.isUserLogged()) {
        expensesAndIncomesManager=new ExpensesAndIncomesManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedUserId());
    }
}

bool PersonalBudget::isUserLogged() {
    userManager.isUserLogged();
}

void PersonalBudget::changeLoggedUserPassword() {
    userManager.changeLoggedUserPassword();
}

void PersonalBudget::userLogout() {
    userManager.userLogout();
}

char PersonalBudget::selectOptionFromMainMenu() {
    return userManager.selectOptionFromMainMenu();
}

char PersonalBudget::selectOptionFromUserMenu() {
    return userManager.selectOptionFromUserMenu();
}

void PersonalBudget::addIncome() {
    expensesAndIncomesManager->addIncome();
}

void PersonalBudget::addExpense() {
    expensesAndIncomesManager->addExpense();
}

void PersonalBudget::currentMonthBalance() {
    expensesAndIncomesManager->currentMonthBalance();
}

void PersonalBudget::previousMonthBalance() {
    expensesAndIncomesManager->previousMonthBalance();
}

void PersonalBudget::chosenPeriodBalance() {
    expensesAndIncomesManager->chosenPeriodBalance();
}
