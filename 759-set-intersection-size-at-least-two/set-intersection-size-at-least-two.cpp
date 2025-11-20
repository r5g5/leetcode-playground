class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (const vector<int>& a, const vector<int>& b) -> bool {
            if (a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });

        int ans = 0, p1 = -1, p2 = -1;

        for (auto& interval : intervals) {
            int left = interval[0], right = interval[1];
            if (p2 < left) {
                ans += 2;
                p1 = right - 1; p2 = right;
            } else if (p1 < left) {
                ans++;
                p1 = p2; p2 = right;
            }
        }
        return ans;
    }
};