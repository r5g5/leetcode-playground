class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (auto& num : nums) {
            ans += (maxValue - num);
        }
        return ans; // TC: O(n), SC: O(1)
    }
};