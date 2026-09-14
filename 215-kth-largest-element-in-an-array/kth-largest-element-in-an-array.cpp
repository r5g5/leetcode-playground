class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1]; // TC: O(nlogn), SC: O(n) [ sorting algorithm space complexity]
    }
};