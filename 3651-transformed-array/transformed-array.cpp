class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int rghtIdx = (i + nums[i]) % n;
                result[i] = nums[rghtIdx];
            } else if (nums[i] < 0) {
                int lftIdx = ((i - abs(nums[i])) % n + n) % n;
                result[i] = nums[lftIdx];
            }
        }
        return result;
    }
};