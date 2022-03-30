#ifndef INCOMES_H
#define INCOMES_H
#include <iostream>

using namespace std;

class Income {
    int incomeId=0;
    int userId=0;
    int date=0;
    string item="";
    float amount=0.0;
public:
    void setIncomeId(int newIncomeId);
	void setUserId(int newUserId);
	void setDate(int newDate);
	void setItem(string newItem);
	void setAmount(float newAmount);

	int getIncomeId();
	int getUserId();
	int getDate();
	string getItem();
	float getAmount();
};

#endif
