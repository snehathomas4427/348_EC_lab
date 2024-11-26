#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double extractNumeric(const string& str){
    bool hasdecimal = false;  // tracks if a decimal point is present
    bool sign = false;     // tracks if a sign is present
    double value = 0.0;
    int decimal = 0; // checks for how many numbers are after the decimal

    for (int i = 0; i < str.length(); i++){
        if (str[i] >= '0' && str[i] <= '9'){
            value = (value * 10) + (str[i] - '0');
            if (hasdecimal == true){
                decimal ++;
            }
        }
        else if (str[i] == '.'){
            if (hasdecimal == true){
                return -999999.99;
            } else {
                hasdecimal = true;
            }
        }
        else if (str[i] == '+' || str[i]== '-'){
            if (sign == true && i != 0){
                return -999999.99;
            }else{
                sign = true;
                if (str[i] == '-'){
                    value = -value;
                }
            }
        }
        else{
            return -999999.99;
        }
    }
    if (hasdecimal == true){
        value = value/pow(10,decimal);
    }
    return value;
}

int main(){
    string input;

    while (true){
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END"){
            break;
        }

        double num = extractNumeric(input);

        if (num != -999999.99){
            cout << "The input is: " << fixed << setprecision(4) << num << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
        
    }
    return 0;
}

// g++ ec_lab.cpp -o main
// ./main
