class Solution {
public:
    int findGCD(vector<int>& nums) {
        // TC: O(n), SC: O(1)
        return __gcd(*min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()));
    }
};