class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // R B G Z Z H H
        // 0 0 0 1 1 1 1
        // 1. All rabbits of same color will gave same answer.
        // 2. Every rabbit will say = (# of rabbit of same color - 1)
        //    Therefore # of rabbit of same color = answers[i] + 1;

        unordered_map<int, int> mp;
        int count = 0;
        for (int n: answers) {
            if (n == 0) count++; // Because there is no rabbit of same color
            else if (mp.find(n) == mp.end()) {
                mp[n] = n; // I am putting in map that I can have N more of that same color possible. 1 is itself
                count += n+1;
            } else {
                mp[n] == 1 ? mp.erase(n) : mp[n]--; // Incase i have exhausted the limit, I just erase it from the map because now new color is needed. 
            }
        }
        return count;
    }
};