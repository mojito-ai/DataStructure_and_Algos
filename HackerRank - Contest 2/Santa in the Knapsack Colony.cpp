#include <bits/stdc++.h>
using namespace std;

/**
 *
 * On the eve of Christmas, Santa wants to distribute N gifts in Knapsack Colony. But in the Knapsack Colony, houses are not numbered sequentially. As Santa is old, he could not remember whether he has already delivered the gift to a particular House Number, Hi (1<= i <=N) or not. Thus, He may deliver one or more than one gifts in some houses and unfortunately none in some :(   

After completing the delivery of all gifts, Santa is wondering who may receive more than K gifts. As Santa is very tired now, Help him find the number of houses which has received more than K gifts.

INPUT
First-line contains two integers N(representing the number of gifts) and K.

The second line contains N-separated integers, H1, H2,........., HN, representing the house-number where Santa is distributing gifts.

OUTPUT
Output the number of houses which has received more than K gifts.

CONSTRAINTS
1 <= N <= 105

1 <= K <= 105

1<= Hi <= 107
 */

// Santa in the Knapsack Colony!
/**
 * Algorithm: Store the hash of count of which houses Santa has visited
 * Optimise: Can also store the house numbers visited in set to avoid traversing 10^7 entries of array
 * 
 */ 

const int T = 1e7;
int hsh[T+10];

int main() {
    int N, K;
    cin >> N >> K;
    unordered_set<int> house;
    for (int i = 1; i<=N; i++) {
        int house_num;
        cin >> house_num;
        hsh[house_num]++;
        house.insert(house_num);
    }

    int count = 0;
    for (auto &p : house) {
        if (hsh[p] > K) count++;
    }

    cout << count << endl;
}