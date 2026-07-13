class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> seqDigits;
        for (int previous = 1; previous <= 8; ++previous) {
            int integer = previous;
            for (int next = previous + 1; next <= 9; ++next) {
                integer = (integer * 10) + next;
                if (integer >= low && integer <= high) {
                    seqDigits.push_back(integer);
                }
            }
        }
        sort(seqDigits.begin(), seqDigits.end());
        return seqDigits; // TC: O(1) [ at max there will be 36 values to compare], SC: O(1) [not considering output as part of SC]
    }
};