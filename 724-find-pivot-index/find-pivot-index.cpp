class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int n = nums.size();
        vector<int> suffixArray(n, 0);
        suffixArray[n-1] = nums[n-1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffixArray[i] = suffixArray[i+1] + nums[i];
        }
        suffixArray.push_back(0);
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            if (prefixSum == suffixArray[i+1])
                return i;
            prefixSum += nums[i];
        }
        return -1; // TC: O(n), SC: O(n)
    }
};