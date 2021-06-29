#include <iostream>
#include <cstring>
#include <iomanip>
#include "introductiontextgenerator.h"
using namespace std;

void printIntroductionText(double p, double roi, int y, int l) {
    int len = strlen("Rate of Interest (in % p.a.)") + l + 9;
    cout << "                 =============================" << endl;
    cout << "                 ||  AMORTIZATION SCHEDULE  ||" << endl;
    cout << "                 =============================" << endl;
    cout << "            " << setfill('=') << setw(len);
    cout << "\n";
    cout << setfill(' ');
    cout << "            || Principal (in HKD)           | " << setw(l) << p << "||" <<endl;
    cout << "            || Rate of Interest (in % p.a.) | " << setw(l) << roi << "||" << endl;
    cout << "            || Number of Years              | " << setw(l) << y << "||" << endl;
    cout << "            " << setfill('=') << setw(len);
    cout << "\n";
}