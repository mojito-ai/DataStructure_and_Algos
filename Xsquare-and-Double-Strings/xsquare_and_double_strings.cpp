#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i<N; i++) {
        cin >> arr[i];
    }

    for(int i=0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            for (int z = i; z<=j; z++) {
                cout << arr[z] << " ";
            }
            cout << endl;
        }
    }
}