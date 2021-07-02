#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <fstream>

#include "scheduleprint.h"

using namespace std;

void schedule(double principal, double interestRate, int installments, double payment) {
    cout << fixed << setprecision(2);
    cout << setfill(' ') << setw(5) << "YR" << setw(5) << "M" << setw(15) << "PR. INIT" << 
        setw(15) << "INT. PAID" << setw(15) << "PR. PAID" << setw(15) << "PR. REM." << endl;

    int year = 0;
    int month = 1;

    ofstream foutI;
    foutI.open("interest.txt", ofstream::out);
    foutI << "Interest" << endl;

    ofstream foutP;
    foutP.open("principal.txt", ofstream::out);
    foutP << "Principal Paid" << endl;
    
    for(int i = 1; i <= installments; i++) {
        if(i % 12 == 1) {
            year += 1;
        }
        if(i % 12 == 0) {
            month = 12;
        }
        else {
            month = i % 12;
        }
        cout << setw(5) << (int)(year);
        cout << setw(5) << (int)(month);
        cout << setw(15) << abs(principal);
        double interest = (interestRate * principal);
        foutI << interest << endl;
        cout << setw(15) << abs(interest);
        cout << setw(15) << abs(payment - interest);
        cout << setw(15) << abs(principal - abs(payment - interest));
        foutP << abs(payment - interest) << endl;
        cout << endl;
        Sleep(200);
        principal = principal - abs(payment - interest);
    }

    cout << "\nWe have reached the end...\n" << endl;

    foutI.close();
    foutP.close();
}