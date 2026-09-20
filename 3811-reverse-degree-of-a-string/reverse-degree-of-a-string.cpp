class Solution {
public:
    int reverseDegree(string s) {
        int revDeg = 0;
        for (int i = 0, n = s.size(); i < n; i++) {
            revDeg += (i + 1) * ('z' - s[i] + 1);
        }
        return revDeg; // TC: O(n), SC: O(1)
    }
};