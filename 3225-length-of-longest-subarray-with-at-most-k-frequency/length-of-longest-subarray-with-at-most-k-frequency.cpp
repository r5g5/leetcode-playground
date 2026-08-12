class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0, i = -1;

        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
            while (freq[nums[j]] > k) {
                i++;
                freq[nums[i]]--;
            }
            ans = max(ans, j - i);
        }

        return ans; // TC: O(n), SC: O(n)
    }
};