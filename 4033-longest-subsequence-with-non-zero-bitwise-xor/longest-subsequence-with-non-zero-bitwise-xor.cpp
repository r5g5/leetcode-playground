class Solution {
private:
    int getXor(const vector<int>& v) {
        int xorVal = 0;
        for (int i : v) {
            xorVal ^= i;
        }
        return xorVal;
    }
public:
    int longestSubsequence(vector<int>& nums) {
        const int n = nums.size();
        if (count(nums.begin(), nums.end(), 0) == n) {
            return 0;
        }
        return getXor(nums) == 0 ? n - 1 : n; // TC: O(n), SC: O(1)
    }
};