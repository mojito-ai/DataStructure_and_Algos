#include <bits/stdc++.h>
using namespace std;

/**
 *
 * Long time ago, in a Galaxy far, far away....A Robotic civilisation lived with Population "N" who used to trade using a currency called "Robo". A Strange thing about this currency is that it can not be broken down and has a fixed value. Like if a Robo is worth 25 value than it cannot be broken down to something like 10,15 of value. If you possess a Robo worth 25 value, than you can only purchase an item worth 25 value with it & purchasing something worth 15 value is impossible with that Robo. Each Robot in the civilisation possess only one Robo worth a particular value as per the rule.

You are given an Integer N>0 which represents the Population of the civilisation & N space seperated integers A[i] , 1 ≤ i ≤ N which represents the value of the Robo possessed by the ith Robot.

A Giant Spaceship is for sale in the Ship Expo & it has a Sale Price worth 'price'. One Robot wants to buy the spaceship but don't have the Robo exactly worth of 'price'. As the sale is for a short time, he can borrow Robo from only one robot of the civilisation due to short time to have Robo worth of 'price'. Help him to know that from how many Robots can he borrow the Robo so that he can buy the Space Ship of his dreams. If he already have a Robo worth of 'price', than he don't need to borrow, simply print '0' in that case. If he can't buy the Space Ship from in any way, than print -1. See the Sample Test case for more clearity.

You are given Q>0 queries. In each query you are given two integers, i & price , where 'i' represents the index of the Robot who wants to buy the spaceship & 'price' represents the price of the Space Ship. Output the number of Robots from which he can borrow Robo to buy the Space Ship or -1 if he can't buy it. Note : All Queries are independent of each other.

INPUT
First line of the Input will consist of a single integer N representing the population, followed by N space separated integers A[i] representing the value of the Robo possessed by ith Robot. Next line inputs Q, the number of queries. Each query inputs two integers i & price.

OUTPUT
For each query, print the number of robots from which the Robo can be borrowed or -1 when he cannot buy the Space Ship in a new line.

CONSTRAINTS
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 105
1 ≤ Q ≤ 105
1 ≤ i ≤ N
1 ≤ price ≤ 2*105
 */

// Borrow Robo!
/**
 * Algorithm
 * 
 * Lets say the price is X and the robot has R robo.
 * 1. He can borrow X-R robo (should be +ve) or
 * 2. He can borrow X robo
 * 3. If X == R then no need to borrow.
 * Make a hash array so that 
 * 
 * This can work since robot is allowed to borrow from only 1 robot
 * 
 */ 

const int T = 1e5;
int hsh[T+10];

int main() {
    int N;
    cin >> N;
    int arr[N+1]; // 1-based indexing
    for (int i = 1; i<=N; i++) {
        cin >> arr[i];
        hsh[arr[i]]++;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int i, price;
        cin >> i >> price;

        if (arr[i] == price) {
            cout << 0 << endl;
            continue;
        } 

        hsh[arr[i]]--; // cant borrow from self
        int borrow = hsh[price];
        if (price > arr[i]) {
            borrow += hsh[price - arr[i]];
        }
        hsh[arr[i]]++; 
        borrow == 0 ? cout << "-1" << endl : cout << borrow << endl;
    }
}