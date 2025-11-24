class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> binaryArray(n, false);
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                curr = nums[i];
            } else {
                curr = (curr << 1) | (nums[i]);
            }

            if (curr % 5 == 0)
                binaryArray[i] = true;
            curr = curr % 5;
        }
        return binaryArray;
    }
};