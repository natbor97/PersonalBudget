#ifndef DATEMETHODS_H
#define DATEMETHODS_H

#include <vector>
#include <sstream>
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

class DateMethods{
public:
    static string dateConverter(int number);
    static string removeDashFromDate(string date);
    static vector<Income>sortingIncomesByDate(vector<Income>& incomes);
    static vector<Expense>sortingExpensesByDate(vector<Expense>& expenses);
};

#endif
