/**
 * Josephus Problem: https://www.geeksforgeeks.org/problems/josephus-problem/1
 * 
 * A total of n people are standing in a circle, and you are one of them playing a game. Starting from a person, k persons will be counted in order along the circle, and the kth person will be killed. Then the next k persons will be counted along the circle, and again the kth person will be killed. This cycle will continue until only a single person is left in the circle.
 * 
 * If there are 5 people in the circle in the order A, B, C, D, and E, you will choose k=3. Starting from A, you will count A, B and C. C will be the 3rd person and will be killed. Then you will continue counting from D, E and then A. A will be third person and will be killed. 
 * 
 * You will be given an array where the first element is the first person from whom the counting will start and the subsequent order of the people. You want to be the last one standing. Determine the index at which you should stand to survive the game. Return an integer denoting safe position. 
 */

#include <vector>
#include <iostream>
using namespace std;

void josephus(int k, int start_index, vector<int> &people) {
    if (people.size() == 1) return;
        
    int index_to_remove = (start_index + k) % people.size();
    
    people.erase(people.begin() + index_to_remove);
            
    josephus(k,index_to_remove,people);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> people;

    for(int i = 1; i<=n; i++) {
        people.push_back(i);
    }
        
    josephus(k-1,0,people);
        
    cout << people[0] << endl;
}
