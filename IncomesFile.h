#ifndef INCOMESFILE_H
#define INCOMESFILE_H
#include <iostream>
#include <vector>
#include <sstream>

#include "Income.h"
#include "Markup.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"
#include "DateMethods.h"
using namespace std;

class IncomesFile: XMLFile {
	int lastIncomeId;

public:
	IncomesFile(string incomesFileName) :
		XMLFile(incomesFileName) {
		lastIncomeId = 0;
	};

	void addIncomeToFile(Income income);
	vector <Income> readIncomesFromFile(int loggedUserId);
	int loadLastIncomeId();
};

#endif
