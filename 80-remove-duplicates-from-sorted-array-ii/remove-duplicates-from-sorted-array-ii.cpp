class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int cntI = count(nums.begin(), nums.end(), nums[i]);
            if (cntI > 2) {
                int j = i + 1;
                while (j < nums.size() && nums[j] == nums[i] && cntI > 2) {
                    nums.erase(nums.begin() + j);
                    cntI--;
                }
            }
        }
        return nums.size();
    }
};