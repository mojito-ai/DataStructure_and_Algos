/**
 * https://codeforces.com/problemset/problem/4/C
 * 
 * A new e-mail service "Berlandesk" is going to be opened in Berland in the near future. The site administration wants to launch their project as soon as possible, that's why they ask you to help. You're suggested to implement the prototype of site registration system. The system should work on the following principle.

Each time a new user wants to register, he sends to the system a request with his name. If such a name does not exist in the system database, it is inserted into the database, and the user gets the response OK, confirming the successful registration. If the name already exists in the system database, the system makes up a new user name, sends it to the user as a prompt and also inserts the prompt into the database. The new name is formed by the following rule. Numbers, starting with 1, are appended one after another to name (name1, name2, ...), among these numbers the least i is found so that namei does not yet exist in the database.

Input
The first line contains number n (1≤n≤10^5). The following n lines contain the requests to the system. Each request is a non-empty line, and consists of not more than 32 characters, which are all lowercase Latin letters.

Output
Print n lines, which are system responses to the requests: OK in case of successful registration, or a prompt with a new name, if the requested name is already taken.

Examples: 

Input
4
abacaba
acaba
abacaba
acab

Output
OK
OK
abacaba1
OK

Input
6
first
first
second
second
third
third

Output
OK
first1
OK
second1
OK
third1
 */ 
#include <bits/stdc++.h>
using namespace std;

/**
 * This program handles a system for user name registration.
 * 
 * Logic:
 * - When a new user name is entered, check if it's already been used.
 * - If it's new, print "OK".
 * - If it's already taken, append a count (e.g., "alex1", "alex2", etc.)
 *   to make it unique and print the new name.
 * 
 * Input:
 * - First line: An integer n — the number of registration attempts.
 * - Following n lines: Strings representing user names to register.
 * 
 * Output:
 * - For each input string, output either:
 *   "OK" if the user name is new, or
 *   the modified unique name if it has already been taken.
 */
int main() {
    int n;
    cin >> n;

    /**
     * A map to track usernames and how many times each has been registered.
     * Key: username (string)
     * Value: count of how many times it's been used.
     */
    map<string, int> m;

    while (n--) {
        string s;
        cin >> s;

        /**
         * If the username is new, insert into map and print "OK".
         * Otherwise, append the current count to the username to generate a new one,
         * insert the new name into the map, and increment the base name's count.
         */
        if (m.find(s) == m.end()) {
            m[s] = 1;
            cout << "OK" << endl;
        } else {
            int count = m[s];
            string new_name = s + to_string(count);
            m[new_name] = 1;
            m[s]++;
            cout << new_name << endl;
        }
    }
}
