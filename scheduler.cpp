#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

#include "introductiontextgenerator.h"

#define MONTHS_IN_YEAR 12
#define PERCENTILE 100

using namespace std;

enum amortizationInputs {
    PRINCIPAL = 1,
    RATE_OF_INTEREST = 2,
    NUMBER_OF_YEARS = 3
};

double calculatePayment(double principal, double rate_of_interest, int number_of_years, int len, int max_len) {
    rate_of_interest = (rate_of_interest / PERCENTILE) / MONTHS_IN_YEAR;
    int installments = (number_of_years * MONTHS_IN_YEAR);
    double payment = (principal * rate_of_interest * pow(1 + rate_of_interest, installments)) / (pow(1 + rate_of_interest, installments) - 1);

    cout << "\n";
    cout << "|| Calculated Monthly Payment | ";
    cout << fixed << setprecision(2) << payment << " ||" << endl;
    cout << "\n";
    cout << "Printing the Schedule..." << endl;
    cout << '\n';

    return payment;
}

int main(int argc, char* argv[]) {
    int len_p = strlen(argv[PRINCIPAL]);
    int len_roi = strlen(argv[RATE_OF_INTEREST]);
    int len_y = strlen(argv[NUMBER_OF_YEARS]);
    int max_len = max(max(len_p, len_roi), len_y);

    double principal = atof(argv[PRINCIPAL]);
    double rate_of_interest = atof(argv[RATE_OF_INTEREST]);
    long number_of_years = atoi(argv[NUMBER_OF_YEARS]);
    
    int len = strlen("Rate of Interest (in % p.a.)") + max_len + 9;
    printIntroductionText(principal, rate_of_interest, number_of_years, max_len);
    double payment = calculatePayment(principal, rate_of_interest, number_of_years, len, max_len);
}