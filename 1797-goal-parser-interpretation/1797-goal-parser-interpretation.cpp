class Solution {
public:
    string interpret(string s) {
        string command;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'G') command.push_back('G');
            else {
                if (s[i+1] == ')') {
                    command.push_back('o');
                    i+=1;
                } else {
                    command.push_back('a');
                    command.push_back('l');
                    i+=3;
                }
            }
        }
        return command;
    }   
};