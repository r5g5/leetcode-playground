class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> numCnt;
        unordered_map<int, int> numPartialCnt;

        const int MOD = (int) 1e9 + 7;

        for (const int& num : nums)
            numCnt[num]++;
        
        int ans = 0;

        for (const int& num : nums) {
            int target = num * 2;
            int leftCnt = numPartialCnt[target];
            numPartialCnt[num]++;
            int rightCnt = numCnt[target] - numPartialCnt[target];
            ans = (ans + (leftCnt * 1LL * rightCnt) % MOD) % MOD;
        }
        
        return ans;
    }
};