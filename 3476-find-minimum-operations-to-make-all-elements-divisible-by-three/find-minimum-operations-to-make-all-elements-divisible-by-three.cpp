class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, [](int acc, int num) {
            return acc + min(3 - num % 3, num % 3);
        });
    }
};