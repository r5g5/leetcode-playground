class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 0, sz = nums.size() - k; i <= sz; i++) {
            int lowest = nums[i];
            int highest = nums[i+k-1];
            ans = min(ans, highest - lowest);
        }
        return ans;
    }
};