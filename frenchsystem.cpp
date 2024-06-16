#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int totalMonths;
    double p, amortization, quota, remaining, interest;
    double import;

    cout << "Calculating the French system. Enter the following:\n";


    int year = 3;
    p = 0.047;
    import = 220000;


    double monthlyInterest = p / 12.0;
    totalMonths = year * 12;


    quota = (import * pow((1 + monthlyInterest), totalMonths) * monthlyInterest) / (pow((1 + monthlyInterest), totalMonths) - 1);
    remaining = import;

    double totalInterestPaid = 0.0;

    cout << fixed << setprecision(2);

    cout << "n \t Cuota \t\t Intereses \t Amortizacion \t Capital pendiente" << endl;
    cout << "0 \t\t\t\t\t\t\t\t\t\t\t " << remaining << " " << endl;

    for (int i = 1; i <= totalMonths; i++) {
        interest = monthlyInterest * remaining;
        amortization = quota - interest;
        remaining -= amortization;
        totalInterestPaid += interest;

        if (i <= 3) {
            cout << i << " \t " << quota << " \t " << interest << " \t " << amortization << " \t " << remaining << " " << endl;
        }
    }

    cout << "\nTotal interest paid over " << year << " years: " << totalInterestPaid << " " << endl;

    return 0;
}
