/**
 * https://codeforces.com/problemset/problem/525/A
 * 
 * After a hard day Vitaly got very hungry and he wants to eat his favorite potato pie. But it's not that simple. Vitaly is in the first room of the house with n room located in a line and numbered starting from one from left to right. You can go from the first room to the second room, from the second room to the third room and so on — you can go from the (n-1)-th room to the n-th room. Thus, you can go to room x only from room x-1.

The potato pie is located in the n-th room and Vitaly needs to go there.

Each pair of consecutive rooms has a door between them. In order to go to room x from room x-1, you need to open the door between the rooms with the corresponding key.

In total the house has several types of doors (represented by uppercase Latin letters) and several types of keys (represented by lowercase Latin letters). The key of type t can open the door of type T if and only if t and T are the same letter, written in different cases. For example, key f can open door F.

Each of the first n-1 rooms contains exactly one key of some type that Vitaly can use to get to next rooms. Once the door is open with some key, Vitaly won't get the key from the keyhole but he will immediately run into the next room. In other words, each key can open no more than one door.

Vitaly realizes that he may end up in some room without the key that opens the door to the next room. Before the start his run for the potato pie Vitaly can buy any number of keys of any type that is guaranteed to get to room n.

Given the plan of the house, Vitaly wants to know what is the minimum number of keys he needs to buy to surely get to the room n, which has a delicious potato pie. Write a program that will help Vitaly find out this number.

Input
The first line of the input contains a positive integer n (2≤n≤105) — the number of rooms in the house.

The second line of the input contains string s of length 2·n-2. Let's number the elements of the string from left to right, starting from one.

The odd positions in the given string s contain lowercase Latin letters — the types of the keys that lie in the corresponding rooms. Thus, each odd position i of the given string s contains a lowercase Latin letter — the type of the key that lies in room number (i+1)/2.

The even positions in the given string contain uppercase Latin letters — the types of doors between the rooms. Thus, each even position i of the given string s contains an uppercase letter — the type of the door that leads from room i/2 to room i/2+1.

Output
Print the only integer — the minimum number of keys that Vitaly needs to buy to surely get from room one to room n.

Input
3
aAbB
Output
0

Input
4
aBaCaB
Output
3

Input
5
xYyXzZaZ
Output
2
 */ 

#include <bits/stdc++.h>
using namespace std;

/**
 * This program simulates a scenario where keys and doors alternate in a string.
 * A lowercase letter represents a key, and an uppercase letter represents a door.
 * 
 * The goal is to determine how many additional keys are needed to open all the doors.
 * 
 * Input:
 * - An integer n representing the length of the string s (should be even).
 * - A string s of length 2n, where every two characters form a key-door pair.
 * 
 * Output:
 * - An integer representing the number of extra keys that must be purchased.
 */
int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    /**
     * 'count' keeps track of the number of keys that need to be bought.
     * 'm' is a map to track available keys.
     */
    int count = 0;
    map<char, int> m;

    /**
     * Iterate through the string in steps of 2:
     * - The first character of the pair is a key (lowercase).
     * - The second is a door (uppercase).
     * 
     * Convert the door to lowercase to check against available keys.
     * If the key exists in the map, use it. Otherwise, increment the count.
     */
    for (int i = 0; i < s.size() - 1; i += 2) {
        char key = s[i];
        char door = tolower(s[i + 1]);

        m[key]++;

        if (m.find(door) == m.end()) {
            count++;
        } else {
            m[door]--;
            if (m[door] == 0) {
                m.erase(door);
            }
        } 
    }

    // Output the total number of keys that had to be bought
    cout << count << endl;
}
