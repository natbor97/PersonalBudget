#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"

using namespace std;

struct compIncome {
    inline bool operator()(Income& firstDate, Income& secondDate) const {
        return firstDate.getDate() < secondDate.getDate();
    }
};

struct compExpense
{
	inline bool operator()(Expense& firstDate, Expense& secondDate) const {
		return firstDate.getDate() < secondDate.getDate();
	}
};

class AuxiliaryMethods {
public:
    static int stringToInt(string number);
    static string intToString(int number);
    static float stringToFloat(string number);
    static string readLine();
    static char readCharacter();
    static int loadInteger();
    static string dateConverter(int number);
    static string removeDashFromDate(string date);
    static vector<Income>sortingIncomesByDate(vector<Income>& incomes);
    static vector<Expense>sortingExpensesByDate(vector<Expense>& expenses);
};

#endif
