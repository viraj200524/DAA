#include <iostream>
#include <string>
#include <algorithm>
#include<cmath>
#include <vector>
using namespace std;




string addStrings(const string& num1, const string& num2) {
    string result;
    int carry = 0;
    int i = num1.length() - 1, j = num2.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        carry = sum / 10;
        result.push_back(sum % 10 + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

string subtractStrings(const string& num1, const string& num2) {
    string result;
    int borrow = 0;
    int i = num1.length() - 1, j = num2.length() - 1;

    while (i >= 0 || j >= 0) {
        int sub = borrow;
        if (i >= 0) sub += num1[i--] - '0';
        if (j >= 0) sub -= num2[j--] - '0';
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(sub + '0');
    }

    // Remove leading zeros and reverse the result
    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

string karatsuba(const string& num1, const string& num2) {
    // Check if any of the numbers is zero
    if (num1.length() == 0 || num2.length() == 0 || num1 == "0" || num2 == "0")
        return "0";  

    // Check for negative numbers
    bool isNegative = false;
    string n1 = num1, n2 = num2;

    if (num1[0] == '-') {
        isNegative = !isNegative;
        n1 = num1.substr(1); // Remove negative sign
    }

    if (num2[0] == '-') {
        isNegative = !isNegative;
        n2 = num2.substr(1); // Remove negative sign
    }

    // Base case: single digit multiplication
    if (n1.length() == 1 || n2.length() == 1)
        return (isNegative ? "-" : "") + to_string(stoi(n1) * stoi(n2));

    int n = max(n1.length(), n2.length());
    int half = (n + 1) / 2;
    
    string a = n1.substr(0, n1.length() - half);
    string b = n1.substr(n1.length() - half);
    string c = n2.substr(0, n2.length() - half);
    string d = n2.substr(n2.length() - half);

    string ac = karatsuba(a, c);
    string bd = karatsuba(b, d);
    string abcd = karatsuba(addStrings(a, b), addStrings(c, d));

    string middle_term = subtractStrings(abcd, addStrings(ac, bd));

    string result = addStrings(addStrings(ac + string(2 * half, '0'), middle_term + string(half, '0')), bd);

    // Add negative sign if necessary
    if (isNegative && result != "0") {
        result = "-" + result;
    }

    return result;
}


int main() 
{
    cout << "\nUsing Karatsuba:\n";

    string num1_00 = "9819807824";
    string num2_00 = "9930247524";
    cout << "\nTest Case 0 (10 digits):" << endl;
    cout << "Result: " << karatsuba(num1_00, num2_00) << endl;


    string num1_10 = "1029384756";
    string num2_10 = "5647382910";
    cout << "\nTest Case 1 (10 digits):" << endl;
    cout << "Result: " << karatsuba(num1_10, num2_10) << endl;

    string num1_11 = "12345678901";
    string num2_11 = "98765432109";
    cout << "\nTest Case 2 (11 digits):" << endl;
    cout << "Result: " << karatsuba(num1_11, num2_11) << endl;

    string num1_12 = "987654321012";
    string num2_12 = "123456789012";
    cout << "\nTest Case 3 (12 digits):" << endl;
    cout << "Result: " << karatsuba(num1_12, num2_12) << endl;

    string num1_13 = "1234567890123";
    string num2_13 = "9876543210987";
    cout << "\nTest Case 4 (13 digits):" << endl;
    cout << "Result: " << karatsuba(num1_13, num2_13) << endl;

    
    string num1_100 = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_100 = "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210";
    cout << "\nTest Case 5 (100 digits):" << endl;
    cout << "Result: " << karatsuba(num1_100, num2_100) << endl;

    string num1_500 = "1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_500 = "9876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210";
    cout << "\nTest Case 6 (500 digits):" << endl;
    cout << "Result: " << karatsuba(num1_500, num2_500) << endl;

    string num1_1000 = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_1000 = "987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210987654321098765432109876543210";
    cout << "\nTest Case 7 (1000 digits):" << endl;
    cout << "Result: " << karatsuba(num1_1000, num2_1000) << endl;

    string num1_21000 = "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";
    string num2_21000 = "0";
    cout << "\nTest Case 8 (1000 digits):" << endl;
    cout << "Result: " << karatsuba(num1_21000, num2_21000) << endl;

    string num1_5 = "-99999";
    string num2_5 = "99999";
    cout << "\nTest Case 9 (5 digits with one negative number):" << endl;
    cout << "Result: " << karatsuba(num1_5, num2_5) << endl;
    return 0;

}
