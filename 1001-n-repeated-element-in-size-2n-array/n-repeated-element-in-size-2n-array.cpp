class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size() / 2;
        for (const int& i : nums) {
            mp[i]++;
            if (mp[i] == n)
                return i;
        }
        return -1;
    }
};