class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for (int i = 1, n = nums.size()-1; i < n; i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i;
            }
        }
        if (nums[0] > nums[nums.size() - 1]) {
            return 0;
        } 
        return nums.size() - 1; // TC: O(n), SC: O(1)
    }
};