/**
 * 
 * https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20
 * 
 * A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:
 * 
 * 't' that evaluates to true.
 * 'f' that evaluates to false.
 * '!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
 * '&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 * '|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
 * Given a string expression that represents a boolean expression, return the evaluation of that expression.
 * 
 * It is guaranteed that the given expression is valid and follows the given rules.
 * 
 */

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
            stack<char> eval;

            bool first=false;
            for (int i=0; i<expression.size(); i++) {
                char c = expression[i];
                switch(c) {
                    case '(' : 
                    case '&' :
                    case '|' :
                    case '!' :
                    case 't' :
                    case 'f' : {
                        eval.push(c);
                        break;
                    }
                    case ')' : {
                        string temp = "";
                        while (eval.top() != '(') {  // Gather all boolean values until '('
                            temp += eval.top();
                            eval.pop();
                        }
                        eval.pop();  // Remove the '('

                        char op = eval.top();  // Get the operator before '('
                        eval.pop();

                        bool localResult;
                        if (op == '&') {
                            // AND operation
                            localResult = temp[0] == 't';
                            for (int i=1; i<temp.size(); i++) {
                                if (temp[i] == 'f') {
                                    localResult = false;
                                    break;  // AND becomes false if any 'f'
                                }
                            }
                        } else if (op == '|') {
                            // OR operation
                            localResult = temp[0] == 't';
                            for (int i=1; i<temp.size(); i++) {
                                if (temp[i] == 't') {
                                    localResult = true;
                                    break;  // OR becomes true if any 't'
                                }
                            }
                        } else if (op == '!') {
                            // NOT operation, only one value to negate
                            localResult = (temp[0] == 'f');  // Negate the first value
                        }
                        eval.push(localResult ? 't' : 'f');  // Push the result back as 't' or 'f'
                        break;
                    }
                    case ',' : {
                        continue;
                    }
                }
            }
        return eval.top() == 't';  // Return true if 't', otherwise false
    }
};