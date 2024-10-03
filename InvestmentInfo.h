#ifndef AIRGEAD_BANKING_INVESTMENTINFO_H
#define AIRGEAD_BANKING_INVESTMENTINFO_H

#include <vector>

using namespace std;

class InvestmentInfo {

public:
    InvestmentInfo();

    const vector<int> &getMYears() const;

    void setMYears(const vector<int> &t_years);

    const vector<double> &getMYearEndBalances() const;

    void setMYearEndBalances(const vector<double> &t_yearEndBalances);

    const vector<double> &getMYearEndEarnedInterests() const;

    void setMYearEndEarnedInterests(const vector<double> &t_yearEndEarnedInterests);

private:
    vector<int> m_years;

    vector<double> m_yearEndBalances;

    vector<double> m_yearEndEarnedInterests;

};


#endif //AIRGEAD_BANKING_INVESTMENTINFO_H