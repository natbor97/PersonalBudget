#include "AuxiliaryMethods.h"

int AuxiliaryMethods::stringToInt(string number){
    int intNumber;
	istringstream iss(number);
	iss >> intNumber;

	return intNumber;
}

string AuxiliaryMethods::intToString(int number){
    ostringstream ss;
	ss << number;
	string str = ss.str();

	return str;
}

float AuxiliaryMethods::stringToFloat(string number)
{
	float intNumber;
	istringstream iss(number);
	iss >> intNumber;

	return intNumber;
}

string AuxiliaryMethods::readLine(){
    string entry = "";
	getline(cin >> ws, entry);

	return entry;
}

char AuxiliaryMethods::readCharacter(){
    string entry = "";
	char sign={0};
	cin.sync();

	while(true){
		getline(cin>>ws, entry);

		if (entry.length() == 1) {
			sign = entry[0];
			break;
		}
		cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
	}

	return sign;
}

int AuxiliaryMethods::loadInteger(){
    string entry = "";
    int number = 0;

    while (true)
    {
        getline(cin>>ws, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

string AuxiliaryMethods::dateConverter(int number){
    string sign = "-";
	ostringstream ss;
	ss << number;
	string str = ss.str();
	str.insert(4, sign);
	str.insert(7, sign);

	return str;
}

string AuxiliaryMethods::removeDashFromDate(string date){
    date.erase(4, 1);
    date.erase(6, 1);

    return date;
}

vector<Income> AuxiliaryMethods::sortingIncomesByDate(vector<Income>& incomes)
{
	sort(incomes.begin(), incomes.end(), compIncome());

	return incomes;
}

vector<Expense> AuxiliaryMethods::sortingExpensesByDate(vector<Expense>& expenses)
{
	sort(expenses.begin(), expenses.end(), compExpense());

	return expenses;
}

