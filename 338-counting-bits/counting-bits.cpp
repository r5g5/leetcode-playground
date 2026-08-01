class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int setBits = 0, x = i;
            while (x > 0) {
                setBits += (x & 1);
                x >>= 1; 
            }
            counts[i] = setBits;
        }
        return counts; // TC: O(nlog10(n)), SC: O(1)
    }
};