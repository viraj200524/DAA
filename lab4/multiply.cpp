#include <iostream>
#include <string>
#include <algorithm>
#include<cmath>
#include <vector>
using namespace std;


string multiplyLargeNumbers(string num1, string num2) 
{
    // Determine if the result should be negative
    bool isNegative = false;
    if (num1[0] == '-') {
        isNegative = !isNegative;  // Flip the sign if num1 is negative
        num1 = num1.substr(1);      // Remove the negative sign
    }
    if (num2[0] == '-') {
        isNegative = !isNegative;  // Flip the sign if num2 is negative
        num2 = num2.substr(1);      // Remove the negative sign
    }

    int n1 = num1.size();
    int n2 = num2.size();
    
    // If either number is zero, the result is zero
    if (num1 == "0" || num2 == "0") return "0";
    
    // Result can be at most n1 + n2 digits long
    vector<int> result(n1 + n2, 0);
    
    // Reverse both numbers to make the calculation easier
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    // Perform multiplication digit by digit
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int digitMul = (num1[i] - '0') * (num2[j] - '0');
            result[i + j] += digitMul;
            result[i + j + 1] += result[i + j] / 10;  // Handle carry
            result[i + j] %= 10;                      // Store the remainder
        }
    }
    
    // Convert result vector back to string
    string resultStr;
    bool leadingZero = true;
    
    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] == 0 && leadingZero) continue;
        leadingZero = false;
        resultStr += (result[i] + '0');
    }
    
    // If the result is empty (shouldn't happen), return "0"
    if (resultStr.empty()) return "0";
    
    // If the result should be negative, prepend a minus sign
    if (isNegative) resultStr = "-" + resultStr;

    return resultStr;
}


int main()
{
    cout<<"\n";
    cout << "Using BRUTE FORCE : " << "/n";

    string num1_00 = "9819807824";
    string num2_00 = "9930247524";
    cout << "\nTest Case 0 (10 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_00, num2_00) << endl;


    string num1_10 = "1029384756";
    string num2_10 = "5647382910";
    cout << "\nTest Case 1 (10 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_10, num2_10) << endl;

    string num1_11 = "12345678901";
    string num2_11 = "98765432109";
    cout << "\nTest Case 2 (11 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_11, num2_11) << endl;

    string num1_12 = "987654321012";
    string num2_12 = "123456789012";
    cout << "\nTest Case 3 (12 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_12, num2_12) << endl;

    string num1_13 = "1234567890123";
    string num2_13 = "9876543210987";
    cout << "\nTest Case 4 (13 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_13, num2_13) << endl;

    
    string num1_100 = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_100 = "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210";
    cout << "\nTest Case 5 (100 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_100, num2_100) << endl;

    string num1_500 = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_500 = "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210";
    cout << "\nTest Case 6 (500 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_500, num2_500) << endl;

    string num1_1000 = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_1000 = "987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210";
    cout << "\nTest Case 7 (1000 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_1000, num2_1000) << endl;

    string num1_21000 = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_21000 = "0";
    cout << "\nTest Case 8 (1000 digits):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_21000, num2_21000) << endl;

    string num1_5 = "-99999";
    string num2_5 = "99999";
    cout << "\nTest Case 0 (5 digits with one negative number):" << endl;
    cout << "Result: " << multiplyLargeNumbers(num1_5, num2_5) << endl;


    return 0;
}