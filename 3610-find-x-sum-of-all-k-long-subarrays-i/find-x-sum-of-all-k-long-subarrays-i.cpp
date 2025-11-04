class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();
        vector<int> ans(n - k + 1);
        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> count;
            for (int j = i; j < i + k; j++) {
                count[nums[j]]++;
            }
            vector<pair<int, int>> p(count.begin(), count.end());
            sort(p.begin(), p.end(), [&] (const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second) {
                    return a.first > b.first;
                }
                return a.second > b.second;
            });
            
            int totalSum = 0;
            for (int c = 0; c < x && c < p.size(); c++) {
                totalSum += p[c].first * p[c].second;
            }
            ans[i] = totalSum;
        }
        return ans;
    }
};