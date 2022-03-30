#include "ExpensesAndIncomesManager.h"

Income ExpensesAndIncomesManager::giveNewIncomeData() {
    Income income;
    int incomeId=0, userId=0, date=0;
    string item="";
    string amountWithComma="";
    float amount=0.0;

    cout<<"Czy przychod dotyczy dnia dzisiejszego? [T/N]"<<endl;
    char choice;

    cin>>choice;
    if (choice=='T')
        date=getPresentDate();
    else if (choice=='N') {
        cout<<"Podaj date ktorej dotyczy przychod: [rrr-mm-dd] ";
        date=insertDate();
    }

    cout<<"Czego dotyczy przychod: ";
    item=AuxiliaryMethods::readLine();
    income.setItem(item);

    cout<<"Wysokosc przychodu: ";
    cin>>amountWithComma;
    amountWithComma=changeCommaToDot(amountWithComma);
    amount=AuxiliaryMethods::stringToFloat(amountWithComma);

    income.setIncomeId(incomesFile.loadLastIncomeId()+1);
    income.setUserId(LOGGED_USER_ID);
    income.setDate(date);
    income.setItem(item);
    income.setAmount(amount);

    return income;
}

Expense ExpensesAndIncomesManager::giveNewExpenseData() {
    Expense expense;
    int expenseId=0, userId=0, date=0;
    string item="";
    string amountWithComma="";
    float amount=0.0;

    cout<<"Czy wydatek dotyczy dnia dzisiejszego? [T/N]" << endl;
    char choice;
    cin>>choice;
    if (choice=='T')
        date=getPresentDate();
    else if (choice=='N') {
        cout<<"Podaj date ktorej dotyczy wydatek: [rrr-mm-dd] ";
        date=insertDate();
    }

    cout<<"Czego dotyczy wydatek: ";
    item=AuxiliaryMethods::readLine();
    expense.setItem(item);

    cout<<"Wysokosc wydatku: ";
    cin>>amountWithComma;
    amountWithComma=changeCommaToDot(amountWithComma);
    amount=AuxiliaryMethods::stringToFloat(amountWithComma);

    expense.setExpenseId(expensesFile.loadLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);
    expense.setDate(date);
    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
}

int ExpensesAndIncomesManager::getPresentDate() {
    string year, month, day;
    time_t t;
    struct tm* ptr;
    time(&t);
    ptr=localtime(&t);
    string date=asctime(ptr);
    year=date.substr(20,4);
    month=date.substr(4,3);
    day=date.substr(8,2);

    map<string, string> months;
    months= {
        {"Jan","01"}, {"Feb","02"}, {"Mar","03"}, {"Apr","04"},
        {"May","05"}, {"Jun","06"}, {"Jul","07"}, {"Aug","08"},
        {"Sep","09"}, {"Oct","10"}, {"Nov","11"}, {"Dec","12"}
    };

    map<string, string>::iterator iter=months.find(month);
    if (iter!=months.end()) {
        month=iter->second;
    }

    date=year+month+day;

    return AuxiliaryMethods::stringToInt(date);
}

int ExpensesAndIncomesManager::insertDate() {
    int newDate;
    string date;
    cin>>date;
    date=AuxiliaryMethods::removeDashFromDate(date);
    newDate=AuxiliaryMethods::stringToInt(date);

    while(checkDateCorectness(newDate)==false) {
        cout<<"Niepoprawna data. Wprowadz date ponownie. "<<endl;
        cin>>date;
        date=AuxiliaryMethods::removeDashFromDate(date);
        newDate=AuxiliaryMethods::stringToInt(date);
    }

    date=AuxiliaryMethods::dateConverter(newDate);
    vector <string> partOfDateContainer;
    stringstream ss(date);
    string item;
    while (getline(ss, item, '-')) {
        partOfDateContainer.push_back(item);
    }

    date=partOfDateContainer[0]+partOfDateContainer[1]+partOfDateContainer[2];

    return AuxiliaryMethods::stringToInt(date);
}

void ExpensesAndIncomesManager::showIncomeData(Income income) {
    string newDate;
    int date=income.getDate();
    newDate=AuxiliaryMethods::dateConverter(date);

    cout<<"Data: "<<newDate;
    cout<<" Kategoria: "<<income.getItem();
    cout<<" Wartosc: "<< income.getAmount()<<endl;
}

void ExpensesAndIncomesManager::showExpenseData(Expense expense) {
    string newDate;
    int date=expense.getDate();
    newDate=AuxiliaryMethods::dateConverter(date);

    cout<<"Data: "<<newDate;
    cout<<" Kategoria: "<<expense.getItem();
    cout<<" Wartosc: "<<expense.getAmount()<<endl;
}

void ExpensesAndIncomesManager::showIncomesAndExpenses(int firstDate, int secondDate) {
    float allIncomes=0.0, allExpenses=0.0;
    if (!incomes.empty()) {
        cout<<endl<<"             >>> PRZYCHODY <<<                 "<<endl;
        cout<<"-----------------------------------------------"<<endl;
        for (vector<Income>::iterator itr=incomes.begin(); itr!=incomes.end(); itr++) {
            if (itr->getDate()>=firstDate && itr->getDate()<=secondDate) {
                allIncomes+=itr->getAmount();
                showIncomeData(*itr);
            }
        }
    } else {
        cout<<"Brak wprowadzonych przychodow."<<endl;
    }
    if (!expenses.empty()) {
        cout<<endl<<"             >>> WYDATKI <<<                   "<<endl;
        cout<<"-----------------------------------------------"<<endl;
        for (vector<Expense>::iterator itr = expenses.begin(); itr!=expenses.end(); itr++) {
            if (itr->getDate()>=firstDate && itr->getDate()<=secondDate) {
                allExpenses+=itr->getAmount();
                showExpenseData(*itr);
            }
        }
    } else {
        cout<<"Brak wprowadzonych wydatkow."<<endl;
    }

    if(allIncomes>0) cout<<endl<<"Wszystkie przychody w podanym okresie: "<<allIncomes << endl;
    else if(allIncomes==0 && !incomes.empty()) cout<<"Brak przychodow w podanym okresie"<<endl;
    if(allExpenses>0)  cout<<"Wszystkie wydatki w podanym okresie: "<<allExpenses << endl;
    else if(allExpenses==0 && !expenses.empty()) cout<<"Brak wydatkow w podanym okresie"<<endl;

    float balance = allIncomes - allExpenses;

    if(!incomes.empty() && !expenses.empty())cout<<endl<<"Calkowity bilans: " <<balance<<endl;
    system("pause");
}

bool ExpensesAndIncomesManager::checkDateCorectness(int date) {
    bool correctDate=true;
    int year, month, day;
    string auxDate = AuxiliaryMethods::intToString(date);
    string auxYear = auxDate.substr(0,4);
    string auxMonth = auxDate.substr(4,2);
    string auxDay = auxDate.substr(6,2);

    year=AuxiliaryMethods::stringToInt(auxYear);
    month=AuxiliaryMethods::stringToInt(auxMonth);
    day=AuxiliaryMethods::stringToInt(auxDay);

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day<1 || day>31) {
            correctDate = false;
            return correctDate;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day<1 || day>30) {
            correctDate = false;
            return correctDate;
        }
        break;
    case 2:
        if (leapyear(year)==true) {
            if (day<1 || day>29) {
                correctDate = false;
                return correctDate;
            }
        } else {
            if (day<1 || day>28) {
                correctDate = false;
                return correctDate;
            }
        }
        break;
    }
    if ((year<2000) || (month<1) || (month>12)) {
        correctDate = false;
        return correctDate;
    }
    return correctDate;
}

bool ExpensesAndIncomesManager::leapyear(int year) {
    if ((year%4==0 && year%100!=0)||(year%400==0)) {
        return true;
    } else {
        return false;
    }
}

string ExpensesAndIncomesManager::changeCommaToDot(string amount) {
    string amountWithDot="";

    for (int characterPosition=0; characterPosition<amount.size(); characterPosition++) {
        if (amount[characterPosition]==',') {
            amountWithDot+=".";
            continue;
        }
        amountWithDot+=amount[characterPosition];
    }
    return amountWithDot;
}

void ExpensesAndIncomesManager::addIncome() {
    Income income=giveNewIncomeData();
    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    cout<<endl<<"Przychod dodany."<<endl;
    system("pause");
}

void ExpensesAndIncomesManager::addExpense() {
    Expense expense=giveNewExpenseData();
    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    cout<<endl<<"Wydatek dodany"<<endl;
    system("pause");
}

void ExpensesAndIncomesManager::currentMonthBalance() {
    float incomesSum=0.0, expensesSum=0.0;
    int date=getPresentDate();
    cout<<endl;
    string firstDate, secondDate;
    int auxFirstDate, auxSecondDate;

    firstDate=AuxiliaryMethods::intToString(date);
    firstDate.replace(6,2,"01");

    secondDate=AuxiliaryMethods::intToString(date);
    secondDate.replace(6,2,"31");

    auxFirstDate=AuxiliaryMethods::stringToInt(firstDate);
    auxSecondDate=AuxiliaryMethods::stringToInt(secondDate);

    incomes=AuxiliaryMethods::sortingIncomesByDate(incomes);
    expenses=AuxiliaryMethods::sortingExpensesByDate(expenses);
    showIncomesAndExpenses(auxFirstDate, auxSecondDate);
}

void ExpensesAndIncomesManager::previousMonthBalance() {
    float incomesSum=0.0, expensesSum=0.0;
    string firstDate, secondDate, newDate, month;
    int auxFirstDate, auxSecondDate;
    int date=getPresentDate();
    newDate=AuxiliaryMethods::intToString(date);
    month=newDate.substr(4, 2);

    map<string, string> months;
    months ={
        {"01","12"}, {"02","01"}, {"03","02"},
        {"04","03"}, {"05","04"}, {"06","05"},
        {"07","06"}, {"08","07"}, {"09","08"},
        {"10","09"}, {"11","10"}, {"12","11"}
    };
    map<string, string>::iterator iter=months.find(month);
    if (iter!=months.end()) {
        month=iter->second;
    }
    cout<<endl;

    firstDate=AuxiliaryMethods::intToString(date);
    firstDate.replace(4,2,month);
    firstDate.replace(6,2,"01");

    secondDate=AuxiliaryMethods::intToString(date);
    secondDate.replace(4,2,month);
    secondDate.replace(6,2,"31");

    auxFirstDate=AuxiliaryMethods::stringToInt(firstDate);
    auxSecondDate=AuxiliaryMethods::stringToInt(secondDate);

    incomes=AuxiliaryMethods::sortingIncomesByDate(incomes);
    expenses=AuxiliaryMethods::sortingExpensesByDate(expenses);
    showIncomesAndExpenses(auxFirstDate, auxSecondDate);
}

void ExpensesAndIncomesManager::chosenPeriodBalance() {
    int firstDate, secondDate;
    float incomesSum=0.0, expensesSum=0.0;
    cout<<"Podaj date, od ktorej przychody/wydatki maja byc liczone: ";
    firstDate=insertDate();
    cout<<"Podaj date, do ktorej przychody/wydatki maja byc liczone: ";
    secondDate=insertDate();
    cout<<endl;

    incomes=AuxiliaryMethods::sortingIncomesByDate(incomes);
    expenses=AuxiliaryMethods::sortingExpensesByDate(expenses);

    showIncomesAndExpenses(firstDate, secondDate);
}
