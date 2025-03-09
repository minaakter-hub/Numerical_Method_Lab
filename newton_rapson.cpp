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


vector<pair<int, int>> derivative(const vector<pair<int, int>> &terms) {
    vector<pair<int, int>> result;
    for (auto [coeff, power] : terms) {
        if (power > 0) {
            result.push_back({coeff * power, power - 1});
        }
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

    vector<pair<int, int>> firstDeri = derivative(terms);


    double x = 0;
    int iterations = 0;

    while (fabs(calculate(terms, x)) !=0) {
        double f1 = calculate(terms, x);
        double f2 = calculate(firstDeri, x);
        cout<< "f(" << x << ") = "<<f1<<" f`(" << x << ") = "<<f2<<endl<<endl;

         x = x - (f1 / f2);

        cout << "Iteration " << iterations << ": x = " << x << endl;
        iterations++;
    }

    cout << "Final root: " << x << endl;
    return 0;
}

