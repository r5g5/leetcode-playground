class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (all_of(nums.cbegin(), nums.cend(), [] (int x) {return x == 0; })) {
            return 0;
        }
        const int xorVal = accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<>());

        return xorVal == 0 ? n - 1 : n; // TC: O(n), SC: O(1)
    }
};