class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        return (nums[0] - 1) * (nums[1] - 1); // TC: O(nlogn), SC: O(1) [not considering space complexity of sorting algorithm]
    }
};