class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // ScanLine Algorithm
        vector<int> pf(n+2, 0);  // Initialize with 0
        for(vector<int> booking: bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];

            pf[first] += seats;
            pf[last+1] -= seats;
        }

        for(int i=1; i<=n; i++) {
            pf[i] += pf[i-1];
        }
        
        return vector<int>(pf.begin()+1, pf.begin()+1+n);
    }
};