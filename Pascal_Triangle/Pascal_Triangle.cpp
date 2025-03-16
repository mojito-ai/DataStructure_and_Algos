#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> pascal;
    pascal.push_back({1});

    for (int i=1; i<N; i++) {
        vector<int> temp;
        for (int j=0; j<=i; j++) {
            if (j==0 || j==i) {
                temp.push_back(1);
            } else {
                temp.push_back(pascal[i-1][j-1] + pascal[i-1][j]);
            }
        }
        pascal.push_back(temp);
    }

    for (vector<int> line : pascal) {
        for (int n : line) {
            cout << n << " ";
        }
        cout << endl;
    }
}

int second_method() { 
    int N;
    cin >> N;

    vector<vector<int>> pascal(N);  // Directly allocate space

    for (int i = 0; i < N; i++) {
        pascal[i].resize(i + 1, 1);  // Initialize row with 1s

        for (int j = 1; j < i; j++) {  // Fill values between the first & last 1
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }

    for (const auto& row : pascal) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}