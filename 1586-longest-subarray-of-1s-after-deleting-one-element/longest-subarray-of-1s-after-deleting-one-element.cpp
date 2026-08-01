class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        vector<int> v = nums;

        if (count(nums.begin(), nums.end(), 1) == nums.size()) {
            return nums.size() - 1;
        }

        int cnt = 0;

        for (int i = 0, n = nums.size(); i < n; i++) {
            if (v[i] == 1) {
                ++cnt;
            } else {
                nums[i] += cnt;
                cnt = 0;
            }
        }

        // for (int i : nums) {
        //     cout << i << " ";
        // }

        cout << endl;

        cnt = 0;
        int ans = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (v[i] == 1) {
                ++cnt;
            } else {
                nums[i] += cnt;
                ans = max(ans, nums[i]);
                cnt = 0;
            }
        }

        // for (int i : nums) {
        //     cout << i << " ";
        // }


        return ans; // TC: O(n), SC: O(n)
    }
};