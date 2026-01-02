class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 1;
        for (int i = 0, n = nums.size() / 2; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                cnt++;
                if (cnt == n)
                    return nums[i];
            } else {
                cnt = 1;
            }
        }
        return -1;
    }
};