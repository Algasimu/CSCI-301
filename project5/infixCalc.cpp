/**
 * problem description:  Design and implement a class of infix calculator.
 * Name: Algassimou Diallo
 * startID: el8524jv
 * Instructor: Jie Meichsner
 * Due date: 07/14/2023
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

using namespace std;

/**
 * InfixCalculator class represents an infix expression calculator.
 * The calculator supports basic arithmetic operators (+, -, *, /),
 * single-digit operands, and parentheses.
 */
class InfixCalculator {
private:
    string infixExpression;         // Data member to store the infix expression

    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    int getPrecedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        else if (op == '*' || op == '/')
            return 2;
        else
            return 0;
    }
     /**
     * Checks if an infix expression is well formed.
     * @return True if the expression is well formed, False otherwise.
     */   
    bool isWellFormed() {
        int openCount = 0;
        int closeCount = 0;
        for (char ch : infixExpression) {
            if (ch == '(')
                openCount++;
            else if (ch == ')')
                closeCount++;
        }
        return (openCount == closeCount);
    }
    /**
     * Checks for balanced brackets in the infix expression.
     * @return True if brackets are balanced, False otherwise.
     */
    bool isBalanced() {
        stack<char> brackets;
        for (char ch : infixExpression) {
            if (ch == '(')
                brackets.push(ch);
            else if (ch == ')') {
                if (brackets.empty())
                    return false;
                brackets.pop();
            }
        }
        return brackets.empty();
    }
    /**
     * Converts an infix expression to postfix notation.
     * @return The postfix expression as a string.
     */
    string convertToPostfix() {
        stack<char> operators;
        string postfixExpression;
        for (char ch : infixExpression) {
            if (isalnum(ch)) {
                postfixExpression += ch;
            } else if (isOperator(ch)) {
                while (!operators.empty() && operators.top() != '(' && getPrecedence(operators.top()) >= getPrecedence(ch)) {
                    postfixExpression += operators.top();
                    operators.pop();
                }
                operators.push(ch);
            } else if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                while (!operators.empty() && operators.top() != '(') {
                    postfixExpression += operators.top();
                    operators.pop();
                }
                operators.pop();  // Discard '('
            }
        }
        while (!operators.empty()) {
            postfixExpression += operators.top();
            operators.pop();
        }
        return postfixExpression;
    }
     /**
     * Evaluates a postfix expression and returns the result.
     * @param postfixExpression The postfix expression to evaluate.
     * @return The result of the evaluation.
     */   
    int evaluatePostfix(const string& postfixExpression) {
        stack<int> operands;
        for (char ch : postfixExpression) {
            if (isalnum(ch)) {
                operands.push(ch - '0');
            } else if (isOperator(ch)) {
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                int result;
                switch (ch) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        if (operand2 == 0)
                            throw runtime_error("Division by zero error");
                        result = operand1 / operand2;
                        break;
                }
                operands.push(result);
            }
        }
        return operands.top();
    }

public:
    /**
     * Default constructor for InfixCalculator class.
     */
    InfixCalculator() {
        infixExpression = "";
    }
    /**
     * Sets the data member with an infix expression after checking if it is valid.
     * @param expression The infix expression to set.
     * @return True if the expression is valid and set successfully, False otherwise.
     */
    bool setExpression(const string& expression) {
        if (!isWellFormed() || !isBalanced())
            return false;
        infixExpression = expression;
        return true;
    }
    /**
     * Evaluates the expression stored in the data member.
     * @return The result of the evaluation.
     */
    int evaluateExpression() {
        string postfixExpression = convertToPostfix();
        cout << "The postfix expression is: " << postfixExpression << endl;
        return evaluatePostfix(postfixExpression);
    }
};

int main() {
    // Create an instance of InfixCalculator
    InfixCalculator calculator;

    // Prompt the user to enter an expression
    while (true) {
        string expression;
        cout << "Enter an infix expression (q to quit): ";
        getline(cin, expression);

        if (expression == "q")
            break;
        
        if (!calculator.setExpression(expression)) {
            cout << "Invalid expression. Please enter a well-formed and balanced infix expression." << endl;
            continue;
        }

        try {
            int result = calculator.evaluateExpression();
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
