#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Simple Calculator\n";
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose operation (+, -, *, /): ";
    cin >> operation;

    double result;
    bool validOperation = true;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } 
            else 
            {
            
                cout << "Error: Division by zero is not allowed." <<endl;
                validOperation = false;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            validOperation = false;
            break;
    }

    if (validOperation) {
        std::cout << "Result: " << result << std::endl;
    }

    return 0;
}
