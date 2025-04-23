#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int sumDigit(int n) {
        if (n==0) return 0;
        return n%10 + sumDigit(n/10);
    }

    int countLargestGroup(int n) {
        map<int, int> m;
        int maximum = 0;
        for (int i = 1; i<=n; i++) {
            int sum = sumDigit(i);
            m[sum]++;
            int count = m[sum];
            maximum = max(count, maximum); 
        }

        int count = 0;
        for (auto it : m) {
            if (it.second == maximum) 
                count++;
        }

        return count;
    }
};