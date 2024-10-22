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