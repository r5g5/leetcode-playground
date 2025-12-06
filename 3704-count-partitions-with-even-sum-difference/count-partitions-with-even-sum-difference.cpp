class Solution {
private:
    int solve(int i, int n, const vector<int>& nums) {
        if (i >= n) {
            return 0;
        } else {
            int evenCnt = 0;
            for (int j = i + 1; j <= n; j++) {
                // Left sum -> [i, j)
                // right sum -> [j, n]
                int leftSum = accumulate(nums.begin(), nums.begin() + j, 0);
                int rightSum = accumulate(nums.begin() + j, nums.end(), 0);
                int diff = abs(leftSum - rightSum);
                if (!(diff & 1)) {
                    evenCnt++;
                }
            }
            return evenCnt;
        }
    }
public:
    int countPartitions(vector<int>& nums) {
        return solve(0, nums.size() - 1, nums);
    }
};