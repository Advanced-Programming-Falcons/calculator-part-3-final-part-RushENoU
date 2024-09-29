#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;


double input1, input2;
char inputOperator;
string history[100];
    
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double times(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

void userInput(){
    string myinput;
    cout << "Enter your calculation (Example: 3+4, h = history, q = quit): " << endl;
    getline(cin, myinput);
    if(myinput == "q"){
        inputOperator = 'q';
        return;
    }
    if(myinput == "h"){
        inputOperator = 'h';
        return;
    }
    stringstream ss(myinput);
    if (!(ss >> input1 >> inputOperator >> input2)) {
        cout << "Bad Input" << endl;
        inputOperator = 'c';
        return;
    }
    return;
}

void showHistory(const string history[], int count) {
    if (count == 0) {
        cout << "No history available." << endl;
    } else {
        cout << "History:" << endl;
        for (int i = 0; i < count; i++) {
            cout << history[i] << endl;
        }
    }
}

int main(){
    bool done = false;
    double result;
    int historyCount = 0; 
    
    while (!done) {
        userInput();
        if (inputOperator == 'q'){
            done = true;
            break;
        }
        
        if (inputOperator == 'h') {
            showHistory(history, historyCount);
            continue;
        }
        
        if (inputOperator == 'c') {
            continue;
        }       
        
        switch(inputOperator){
            case '+':
                result = add(input1, input2);
                break;
            case '-':
                result = subtract(input1, input2);
                break;
            case '*':
                result = times(input1, input2);
                break;
            case '/':
                result = divide(input1, input2);
                break;
            case '^':
                result = power(input1, input2);
                break;
            default:
            cout << "Bad Input" << endl;
            continue;
        }
        
        cout << "Result: " << result << endl;
        history[historyCount] = to_string(input1) + " " + inputOperator + " " + to_string(input2) + " = " + to_string(result);
        historyCount++;

        
    }
    return 0;
}
