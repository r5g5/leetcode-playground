class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = (int) 1e9 + 7;
        unordered_map<int, int> pointNum;
        long long ans = 0, sum = 0;
        for (auto& point : points) {
            pointNum[point[1]]++;
        }   

        for (auto& [_, edge] : pointNum) {
            long long edges = (edge * (edge - 1LL)) / 2;
            ans += sum * edges;
            sum += edges;
            ans %= mod;
        }

        return ans % mod;
    }
};