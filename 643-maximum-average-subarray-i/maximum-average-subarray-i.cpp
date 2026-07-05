class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.begin() + k, 0);
        int i = 0, j = k, n = nums.size();
        double calcMean = totalSum / static_cast<double>(k);
        double maxAverage = calcMean;
        while (j < n) {
            totalSum -= nums[i++];
            totalSum += nums[j++];
            calcMean = totalSum / static_cast<double>(k);
            maxAverage = max(maxAverage, calcMean);
        }
        return maxAverage; // TC: O(n), SC: O(1)
    }
};