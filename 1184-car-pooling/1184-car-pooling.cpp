class Solution {
public:

    /*
    *
    * Scanline Algorithm: The Scanline Algorithm is an optimization technique used for range updates 
    * and range queries in an  * efficient manner. It is commonly applied in computational geometry, 
    * interval problems, and prefix sum optimizations.
    * 
    * Key Concept: Instead of updating each element in a range one by one (which can be slow for large inputs), 
    * we mark the beginning and end of an update efficiently and then use a prefix sum to compute the final values.
    */

    static const int N = 1e3;
    int arr[N+10];
    int pf[N+10];
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for (vector<int> trip: trips) {
            arr[trip[1]+1] += trip[0];
            arr[trip[2]+1] -= trip[0];
        }

        // Calculating Prefix Sum
        for(int i = 1; i<=N; i++) {
            pf[i] = arr[i] + pf[i-1];
            if (pf[i] > capacity) return false;
        }

        return true;
    }
};