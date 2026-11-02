class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int median = nums[nums.size() / 2];
        int ans = 0;
        for (const auto& num : nums) {
            ans += abs(num - median);
        }
        return ans; // TC: O(nlogn), SC: O(n) [ sorting algorithm takes O(n) space ]
    }
};