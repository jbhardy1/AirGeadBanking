#include <vector>
#include "InvestmentInfo.h"

using namespace std;

// Constructor
InvestmentInfo::InvestmentInfo() {}

const vector<int> &InvestmentInfo::getMYears() const {
    return m_years;
}

void InvestmentInfo::setMYears(const vector<int> &t_years) {
    m_years = t_years;
}

const vector<double> &InvestmentInfo::getMYearEndBalances() const {
    return m_yearEndBalances;
}

void InvestmentInfo::setMYearEndBalances(const vector<double> &t_yearEndBalances) {
    m_yearEndBalances = t_yearEndBalances;
}

const vector<double> &InvestmentInfo::getMYearEndEarnedInterests() const {
    return m_yearEndEarnedInterests;
}

void InvestmentInfo::setMYearEndEarnedInterests(const vector<double> &t_yearEndEarnedInterests) {
    m_yearEndEarnedInterests = t_yearEndEarnedInterests;
}