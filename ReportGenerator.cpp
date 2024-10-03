#include <string_view>
#include <iostream>
#include <iomanip>
#include "ReportGenerator.h"
#include "Calculations.h"

using namespace std;

const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

// Constructor
ReportGenerator::ReportGenerator() {}

/**
 * Print the report column titles
 */
void ReportGenerator::printColHeader() {
    cout << string(66, '=') << endl;
    cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST << endl;
    cout << string(66, '-') << endl;
}

/**
 * Print the report header
 * @param t_dataOne
 * @param t_dataTwo
 */
void ReportGenerator::reportGenerator(InvestmentInfo  &t_dataOne, InvestmentInfo  &t_dataTwo) {
    cout <<"     Balance and Interest Without Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataOne);

    cout <<"     Balance and Interest With Additional Monthly Deposits     \n" << endl;
    annualReport(t_dataTwo);
}

/**
 * Print the rows of financial info for the report
 * @param data
 */
void ReportGenerator::annualReport(InvestmentInfo  &t_data) {
    // Set local vars to producing accurate report
    vector<int> years = t_data.getMYears();
    vector<double> yearEndBalances = t_data.getMYearEndBalances();
    vector<double> yearEndEarnedInterests = t_data.getMYearEndEarnedInterests();

    printColHeader();

    // Loop over InvestmentInfo object to fill out report
    for (int i = 0; i < years.size(); ++i) {
        cout << setw(9) << years.at(i) << fixed << setprecision(2);
        cout << setw(26) << yearEndBalances.at(i) << fixed << setprecision(2);
        cout << setw(27) << yearEndEarnedInterests.at(i) << fixed << setprecision(2)<< endl;
    }
    cout << endl << endl;
}

/**
 * Prompt user for additinoal session
 * @return bool
 */
bool ReportGenerator::additionalSessionCheck() {
    string text;

    cout << "Press enter to try more values (press 'q' to quit)\n";
    getline(cin, text);

    if (text.empty()) {
        return true;
    }
    else {
        return false;
    }
}
