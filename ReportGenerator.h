#ifndef AIRGEAD_BANKING_REPORTGENERATOR_H
#define AIRGEAD_BANKING_REPORTGENERATOR_H

#include <vector>
#include "DataInput.h"
#include "Calculations.h"
#include "InvestmentInfo.h"

using namespace std;

class ReportGenerator {
public:
    ReportGenerator();

    void reportGenerator(InvestmentInfo  &t_dataOne, InvestmentInfo  &dataTwo);

    bool additionalSessionCheck();

private:
    void printColHeader();

    void annualReport(InvestmentInfo  &t_data);

};

#endif //AIRGEAD_BANKING_REPORTGENERATOR_H