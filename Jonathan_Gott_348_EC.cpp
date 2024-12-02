#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double extractNumeric(const string& str);

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}

// Function that extracts a numeric value from the string
double extractNumeric(const string& str) {
    bool hasDecimal = false;
    bool hasSign = false;
    string numericPart = "";

    for (size_t i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (isdigit(ch)) {
            numericPart += ch;
        } else if (ch == '.' && !hasDecimal) {
            numericPart += ch;
            hasDecimal = true;
        } else if ((ch == '+' || ch == '-') && i == 0 && !hasSign) {
            numericPart += ch;
            hasSign = true;
        } else {
            return -999999.99; // Invalid character found
        }
    }

    if (numericPart == "" || numericPart == "+" || numericPart == "-" || numericPart == "." || numericPart == "+." || numericPart == "-.") {
        return -999999.99; // Invalid number format
    }

    // Convert the valid string to double
    try {
        return stod(numericPart);
    } catch (...) {
        return -999999.99; // look for any conversion error
    }
}
