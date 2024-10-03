#include <iostream>
#include <vector>
#include "DataInput.h"

using namespace std;

// Default constructor
DataInput::DataInput() {
    DataInput::m_userPrompts = {
        "Initial Investment Amount:  ",
                "Monthly Deposit:  ",
                "Annual Interest:  ",
                "Number of Years:  "
    };
};

const vector<string> &DataInput::getMUserPrompts() const {
    return m_userPrompts;
}

// Getters & Setters
double DataInput::getMInitialInvestAmt() const {
    return m_initialInvestAmt;
}

void DataInput::setMInitialInvestAmt(double t_initialInvestAmt) {
    m_initialInvestAmt = t_initialInvestAmt;
}

double DataInput::getMMonthlyDep() const {
    return m_monthlyDep;
}

void DataInput::setMMonthlyDep(double t_monthlyDep) {
    m_monthlyDep = t_monthlyDep;
}

double DataInput::getMAnnualInt() const {
    return m_annualInt;
}

void DataInput::setMAnnualInt(double t_annualInt) {
    m_annualInt = t_annualInt;
}

double DataInput::getMNumYears() const {
    return m_numYears;
}

void DataInput::setMNumYears(double t_numYears) {
    m_numYears = t_numYears;
}

/**
 * Print header for user input prompt
 */
void DataInput::printHeader() {
    cout << string(36, '*') << endl;
    cout << string(12, '*') << " Data Input " << string(12, '*') << endl;
}

/**
 * Capture user input and set class members
 */
void DataInput::promptUser() {
    vector<double> depositDetails;
    char quitCmd = 'a';  // Indicates infinite loop till user satisfies input requirements

    while (quitCmd != 'q') {

        try {
            // Clear any previously unfinished collections of user input
            depositDetails.clear();
            // Display interface header
            printHeader();
            // Collect user input
            depositDetails = inputCapture();

        }
        // Catch any invalid arguments and handle them gracefully
        catch (invalid_argument& except) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
            cout << except.what() << endl;
        }

        // Check that depositDetails vector is full and user decides to continue
        if (depositDetails.size() == 4 && enterCheck()) {
            // Set our class's private members
            setMInitialInvestAmt(depositDetails.at(0));
            setMMonthlyDep(depositDetails.at(1));
            setMAnnualInt(depositDetails.at(2));
            setMNumYears(depositDetails.at(3));

            // Exit this class and return to main()
            quitCmd = 'q';
        }
    }
}

/**
 * Loop over user prompts and store responses
 * @return responses
 */
vector<double> DataInput::inputCapture() {
    // Collect user input and organize in a tidy vector
    vector<double> responses;
    vector<string> prompts = getMUserPrompts();

    for (int i = 0; i < prompts.size(); ++i) {
        string prompt = prompts.at(i);
        double userInput;
        cout << prompt;
        cin >> userInput;

        // Check for valid user input
        if (!cin || userInput < 0.01) {
            throw invalid_argument("\n\nAlphabetical characters and amounts less than .01 not allowed. \n\n"
            "Please try again.\n\n");
        }

        // Add user input to our vector
        responses.push_back(userInput);
    }
    return responses;
}

/**
 * An abstracted method for validating specific enter key presses
 * @return bool
 */
bool DataInput::enterCheck() {
    cout << "Press enter to continue . . .\n\n\n";
    return cin.get() == '\n';
}