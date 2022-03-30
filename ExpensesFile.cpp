#include "ExpensesFile.h"

void ExpensesFile::addExpenseToFile(Expense expense){
    CMarkup xml;
	bool fileExists = xml.Load(getFileName());

	string newDate;
	int date = expense.getDate();
	newDate = DateMethods::dateConverter(date);

	ostringstream temporaryString;
	temporaryString << expense.getAmount();
	string amountAsString = temporaryString.str();

	if (!fileExists) {
		xml.AddElem("Expenses");
	}

	xml.FindElem();
	xml.IntoElem();
	xml.AddElem("Expense");
	xml.IntoElem();
	xml.AddElem("ExpenseId", expense.getExpenseId());
	xml.AddElem("UserId", expense.getUserId());
	xml.AddElem("Date", newDate);
	xml.AddElem("Item", expense.getItem());
	xml.AddElem("Amount", amountAsString);
	lastExpenseId++;

	xml.Save(getFileName());
}

vector<Expense> ExpensesFile::readExpensesFromFile(int loggedUserId){
    CMarkup xml;
	Expense expense;
	vector <Expense> expenses;
	xml.Load(getFileName());

	xml.FindElem();
	xml.IntoElem();
	while (xml.FindElem("Expense")) {
		xml.IntoElem();

		xml.FindElem("ExpenseId");
		MCD_STR strSN = xml.GetData();
		expense.setExpenseId(AuxiliaryMethods::stringToInt(strSN));
		xml.FindElem("UserId");
		strSN = xml.GetData();
		expense.setUserId(AuxiliaryMethods::stringToInt(strSN));

		xml.FindElem("Date");
		strSN = xml.GetData();
		strSN.erase(4, 1);
		strSN.erase(6, 1);
		expense.setDate(AuxiliaryMethods::stringToInt(strSN));

		xml.FindElem("Item");
		strSN = xml.GetData();
		expense.setItem(strSN);

		xml.FindElem("Amount");
		strSN = xml.GetData();
		expense.setAmount(AuxiliaryMethods::stringToFloat(strSN));
		xml.OutOfElem();

		lastExpenseId++;
		if(loggedUserId == expense.getUserId())
			expenses.push_back(expense);
	}

	return expenses;
}

int ExpensesFile::loadLastExpenseId(){
    return lastExpenseId;
}
