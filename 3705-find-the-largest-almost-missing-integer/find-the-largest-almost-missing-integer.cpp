class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        const int n = nums.size();
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        } 
        array<int, 51> count;
        fill(begin(count), end(count), 0);
        for (int x : nums) {
            count[x]++;
        }
        if (k == 1) {
            for (int i = 50; i >= 1; i--) {
                if (count[i] == 1)
                    return i;
            }
            return -1;
        }
        int res = -1;
        if (count[nums.front()] == 1) {
            res = max(res, nums.front());
        }
        if (count[nums.back()] == 1) {
            res = max(res, nums.back());
        }
        return res; // TC: O(n), SC: O(1) [ we are always creating a count array of size 51]
    }
};