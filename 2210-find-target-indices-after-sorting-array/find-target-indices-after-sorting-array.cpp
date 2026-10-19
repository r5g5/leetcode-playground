class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i] == target) {
                ans.push_back(i);
            }
        }
        return ans; // TC: O(nlogn), SC: O(n) [ sorting algorithm takes O(n) space]
    }
};