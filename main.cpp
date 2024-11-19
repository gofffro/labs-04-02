#include <iostream>
#include <string>
#include <map>

using namespace std;

int romeToInt(string strRome) {
    map<char, unsigned> numbersRome;
    char prevValue = '\0';
    int valueInt = 0;
    numbersRome['I'] = 1;
    numbersRome['V'] = 5;
    numbersRome['X'] = 10;
    numbersRome['L'] = 50;
    numbersRome['C'] = 100;
    numbersRome['D'] = 500;
    numbersRome['M'] = 1000;

    for (int i = 0; i < strRome.length(); ++i) {
        if (prevValue != '\0') {
            if (numbersRome[prevValue] < numbersRome[strRome[i]]) {
                valueInt += numbersRome[strRome[i]] - numbersRome[prevValue] * 2;
            }
            else {
                valueInt += numbersRome[strRome[i]];
            }
        }
        else {
            valueInt += numbersRome[strRome[i]];
        }
        prevValue = strRome[i];
    }
    
    return valueInt;   
}

string intToRome (int numberInt) {
    string inputVal;
    int valuesInt[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string strRome[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int lenValues = sizeof(valuesInt) / sizeof(valuesInt[0]);
    for (int i = 0; i < lenValues; ++i) {
        while (numberInt >= valuesInt[i]) {
            numberInt -= valuesInt[i];
            inputVal.append(strRome[i]);
        }
    }
    
    return inputVal;
}

int main() {
    int numberInt;
    string strRome;

    cout << "Введите арабское число (1 до 3999): ";
    cin >> numberInt;
    cout << "Римское число: " << intToRome(numberInt) << endl;
    
    cout << "Введите римское число (1 до 3999): ";
    cin >> strRome;
    cout << "Арабское число: " << romeToInt(strRome) << endl;
}
