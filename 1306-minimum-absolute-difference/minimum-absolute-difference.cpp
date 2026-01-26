class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 0, n = arr.size() - 1; i < n; i++) {
            minDiff = min(minDiff, arr[i+1] - arr[i]);
        }
        vector<vector<int>> ans;
        for (int i = 0, n = arr.size(); i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] - arr[i] == minDiff) {
                    ans.emplace_back(vector<int>{arr[i], arr[j]});
                } else if (arr[j] - arr[i] > minDiff)
                    break;
            }
        }
        return ans;
    }
};