class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int ans = 1;

        for (int i = 0, n = nums.size(); i < n; i++) {
            int incLen = 1;
            for (int next = i + 1; next < n; next++) {
                if (nums[next] > nums[next-1]) {
                    incLen++;
                    continue;
                }
                break;
            }
            ans = max(ans, incLen);
        }

        for (int i = 0, n = nums.size(); i < n; i++) {
            int decLen = 1;
            for (int next = i + 1; next < n; next++) {
                if (nums[next] < nums[next-1]) {
                    decLen++;
                    continue;
                }
                break;
            }

            ans = max(ans, decLen);
        }

        return ans; // TC: O(n^2), SC: O(1)
    }
};