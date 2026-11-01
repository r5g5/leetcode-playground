class Solution {
public:
    int minMoves(vector<int>& nums) {
        const auto minElement = *min_element(nums.begin(), nums.end());
        return accumulate(nums.begin(), nums.end(), 0) - (nums.size() * minElement);
        // TC: O(n), SC: O(1)
    }
};