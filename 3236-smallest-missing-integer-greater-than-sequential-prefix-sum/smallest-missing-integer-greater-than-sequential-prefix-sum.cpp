class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> elements;
        elements.insert(nums[0]);
        bool isSequential = true;
        int sum = nums[0];
        for (int i = 1, n = nums.size(); i < n; i++) {
            if (isSequential and (nums[i] == nums[i-1] + 1)) {
                sum += nums[i];
            } else {
                isSequential = false;
            }
            elements.insert(nums[i]);
        }
        while (elements.count(sum)) {
            sum++;
        }
        return sum; // TC: O(n), SC: O(n)
    }
};