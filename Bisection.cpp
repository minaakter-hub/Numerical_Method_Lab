#include <bits/stdc++.h>
using namespace std;


double calculate(vector<pair<int, int>> &terms, double x) {
    double result = 0;
    for (auto &term : terms) {
        int coeff = term.first;
        int power = term.second;
        result += coeff * pow(x, power);
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of terms in the polynomial: ";
    cin >> n;

    vector<pair<int, int>> terms;

    cout << "Enter coefficients and powers:" << endl;
    for (int i = 0; i <= n; i++) {
        int coeff, power;
        cin >> coeff >> power;
        terms.push_back({coeff, power});
    }

    double x1, x2, stop,f1,f2;
    cout << "Stopping Criteria: ";
    cin >> stop;


    while (true) {
        cout << "Enter the guessing values: ";
        cin >> x1 >> x2;

         f1 = calculate(terms, x1);
         f2 = calculate(terms, x2);

        if (f1 * f2 > 0) {
                cout<<f1<<" "<<f2<<endl;
            cout << "Error: f(" << x1 << ") * f(" << x2 << ") > 0. Abr cesta korun" << endl;
        } else {
            break;
        }
    }

    double x0, f0;
    int iterations = 0;


    while (true) {
        iterations++;
        x0 = (x1 + x2) / 2;
        f0 = calculate(terms, x0);



        if (calculate(terms, x1) * f0 < 0) {
            x2 = x0;
        } else {
            x1 = x0;
        }
        cout<<x1<<" "<<x2<<endl;

         if (fabs(x2 - x1) < stop) {
            cout << "Root hocce " << (x1+x2)/2 << endl;
            cout << "Iteration lagce " << iterations << " iterations." << endl;
            break;
        }
    }

    return 0;
}
