class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&] (const auto& interval1, const auto& interval2) -> bool {
            if (interval1[0] == interval2[0]) {
                return interval1[1] > interval2[1];
            }
            return interval1[0] < interval2[0];
        });

        int nofOfRemIntervals = 0, maxEnd = INT_MIN;

        for (int i = 0; i < intervals.size(); i++) {
            if (maxEnd < intervals[i][1]) {
                nofOfRemIntervals++;
            }
            maxEnd = max(maxEnd, intervals[i][1]);
        }

        return nofOfRemIntervals;
    }
};