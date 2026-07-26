class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const auto n = nums.size();
        return max(
            nums[0] * nums[1] * nums[n-1],
            nums[n-1] * nums[n-2] * nums[n-3]
        ); // TC: O(nlogn), SC: O(1) [not considering time complexity of sorting algorithm]  
    }
};