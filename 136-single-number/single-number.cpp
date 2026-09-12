class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for_each(nums.begin(), nums.end(), [&ans] (const int x) -> void { ans ^= x; });
        return ans; // TC: (n), SC: O(1)
    }
};