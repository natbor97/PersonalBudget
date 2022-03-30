#include "DateMethods.h"

string DateMethods::dateConverter(int number){
    string sign = "-";
	ostringstream ss;
	ss << number;
	string str = ss.str();
	str.insert(4, sign);
	str.insert(7, sign);

	return str;
}

string DateMethods::removeDashFromDate(string date){
    date.erase(4, 1);
    date.erase(6, 1);

    return date;
}

vector<Income> DateMethods::sortingIncomesByDate(vector<Income>& incomes)
{
	sort(incomes.begin(), incomes.end(), compIncome());

	return incomes;
}

vector<Expense> DateMethods::sortingExpensesByDate(vector<Expense>& expenses)
{
	sort(expenses.begin(), expenses.end(), compExpense());

	return expenses;
}
