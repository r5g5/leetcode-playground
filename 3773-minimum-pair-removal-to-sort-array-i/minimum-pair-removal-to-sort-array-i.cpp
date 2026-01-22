class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int noOfOps = 0;
        while (nums.size() > 1) {
            bool isAscending = true;
            int index = 0, minSum = INT_MAX;
            for (int i = 0; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i+1])
                    isAscending = false;
                int sum = nums[i] + nums[i+1];
                if (sum < minSum) {
                    minSum = sum;
                    index = i;
                }
            }
            if (isAscending)
                break;
            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);
            ++noOfOps;
        }
        return noOfOps;
    }
};