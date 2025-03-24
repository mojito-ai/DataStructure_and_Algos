#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int nums[26] = {0};
        bool flag = false;
        // Algorithm A=B means every char in A is in B
        // It means that if I have even 1 pair of repeating chars
        // Then I can construct a special string by removing all other chars. 
        for (int i = 0; i<s.size(); i++) {
            nums[s[i]-'a']++;
            if(nums[s[i]-'a'] == 2) {
                flag = true;
                break;
            }
        }

        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}