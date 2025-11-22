class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for (auto& num : nums) {
            int div = ceil(num / 3.0);
            int res = min(3 * div - num, num % 3);
            ans += res;
        }
        return ans;
    }
};