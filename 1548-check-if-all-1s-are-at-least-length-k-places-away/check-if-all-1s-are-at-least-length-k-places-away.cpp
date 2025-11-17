class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevOne = -1;
        for (int i = 0, n = nums.size(); i < n; i++) {
            if (nums[i]) {
                if ((prevOne != -1) && (i - prevOne - 1) < k)
                    return false;
                prevOne = i;
            }
        }
        return true;
    }
};