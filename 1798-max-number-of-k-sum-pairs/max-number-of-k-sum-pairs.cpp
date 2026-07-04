class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ops = 0, i = 0, j = nums.size() - 1;
        while (i < j) {
            int totalSum = nums[i] + nums[j];
            if (totalSum == k) {
                ops++;
                i++;
                j--;
            } else if (totalSum < k) {
                i++;
            } else {
                j--;
            }
        }
        return ops;
    }
};