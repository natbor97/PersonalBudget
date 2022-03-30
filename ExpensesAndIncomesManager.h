#ifndef EXPENSESANDINCOMESMANAGER_H
#define EXPENSESANDINCOMESMANAGER_H
#include <iostream>
#include <vector>
#include <Ctime>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
#include "Income.h"
#include "Expense.h"
#include "UserManager.h"
#include "IncomesFile.h"
#include "ExpensesFile.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"

class ExpensesAndIncomesManager {
	const int LOGGED_USER_ID;
	vector<Income> incomes;
	vector<Expense> expenses;

	Income giveNewIncomeData();
	Expense giveNewExpenseData();
	int getPresentDate();
	int insertDate();
	void showIncomeData(Income income);
	void showExpenseData(Expense expense);
	IncomesFile incomesFile;
	ExpensesFile expensesFile;
	void showIncomesAndExpenses(int firstDate, int secondDate);
	bool checkDateCorectness(int date);
	bool leapyear(int year);
	string changeCommaToDot(string amount);
public:
	ExpensesAndIncomesManager(string incomesFileName, string expensesFileName, int loggedUserId) :
		incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId)
	{
		incomes = incomesFile.readIncomesFromFile(LOGGED_USER_ID);
		expenses = expensesFile.readExpensesFromFile(LOGGED_USER_ID);
	};

	void addIncome();
	void addExpense();
	void currentMonthBalance();
	void previousMonthBalance();
	void chosenPeriodBalance();
};

#endif
