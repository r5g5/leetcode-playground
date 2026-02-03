class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1;
        while (i < nums.size() && nums[i] > nums[i-1]) {
            i++;
        }

        int p = i - 1;

        while (i < nums.size() && nums[i] < nums[i-1]) {
            i++;
        }

        int q = i - 1;

        while (i < nums.size() && nums[i] > nums[i-1]) {
            i++;
        }

        return (p > 0) && (p < q) && (q < nums.size() - 1) && (i == nums.size());
    }
};