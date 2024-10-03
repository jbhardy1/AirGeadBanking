#include <vector>
#include <iostream>
#include "Calculations.h"
#include "InvestmentInfo.h"

using namespace std;

const long MAX_AMOUNT = 9999999999999999;

// Default constructor
Calculations::Calculations() {}

/**
 * Takes user input and builds InvestmentInfo object that contains user balance & interest info.
 * @param t_userData
 * @param t_monthlyDep
 * @return investmentSansMonthlyDep
 */
InvestmentInfo Calculations::calculateAnnualInvestment(DataInput& t_userData, bool t_monthlyDep) {
    // For ease of use, let's sort our user input
    double openAmt =  t_userData.getMInitialInvestAmt();
    double depAmt =  t_userData.getMMonthlyDep();
    int intRate =  t_userData.getMAnnualInt();
    int numYears =  t_userData.getMNumYears();
    vector<int> years;
    vector<vector<double>> yearEndBals;

    // Create an object to store data for our report
    InvestmentInfo investmentDetails;

    try {

        // Return years as array of ints for display to the user
        for (int i = 0; i < numYears; ++i) {
            years.push_back(i + 1);
        }

        if (t_monthlyDep == false) {
            // Calculate without monthly deposit
            yearEndBals = annualBalWithInt(openAmt, 0, intRate, numYears);
        } else {
            // Calculate with monthly deposits
            yearEndBals = annualBalWithInt(openAmt, depAmt, intRate, numYears);
        }

        // Populate Investment object properties
        investmentDetails.setMYears(years);
        investmentDetails.setMYearEndEarnedInterests(yearEndBals.at(0));
        investmentDetails.setMYearEndBalances(yearEndBals.at(1));

        return investmentDetails;
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
    }

}

/**
 * Calculates annual account balance & earned interest
 * @param t_openAmount
 * @param t_depositAmount
 * @param t_intRate
 * @param t_years
 * @return balanceAndInts
 */
vector<vector<double>> Calculations::annualBalWithInt(double t_openAmount, double t_depositAmount, int t_intRate, int t_years) {
    // Local vars to manipulate data for accurate calculations
    vector<vector<double>> balanceAndInts;
    vector<double> annualInterestOnly;
    vector<double> annualBalWithInterest;
    double newBal;
    double yearEndInt;
    double precIntRate = (t_intRate/100.00)/12.00;
    double intTracker = 0;
    double intOnly = 0;

    // Loop over months in requested time frame and calculate annual balance & earned interest
    for (int i = 0; i < (t_years * 12); ++i) {
        yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i+1))) * precIntRate;
        // Allows tracking earned interest back into principle
        intTracker = yearEndInt;
        if (((i+1) % 12) == 0) {
            annualInterestOnly.push_back(yearEndInt - intOnly); // Add just the annual interest to one vector first
            intOnly = yearEndInt;
            newBal = t_openAmount + (t_depositAmount * (i+1)) + yearEndInt; // Add interest, opening, & monthly amount
            annualBalWithInterest.push_back(newBal); // Add annual bal with interest to a second vector
        }
    }

    if (newBal > MAX_AMOUNT ) {
        throw runtime_error("Unable to complete calculation. Amount too large.");
    }

    balanceAndInts.push_back(annualInterestOnly); // One vector for tracking interest
    balanceAndInts.push_back(annualBalWithInterest); // One vector for tracking interest + balance

    // Pass vectors back to fill out InvestmentInfo objects
    return balanceAndInts;
}