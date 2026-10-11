class Solution {
    struct DateInfo {
        int temperature;
        int index;
        DateInfo(const int temp, const int idx) : temperature(temp), index(idx) {}
    };
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<DateInfo> s;
        const int n = temperatures.size();
        vector<int> results(n, 0);
        for (int i = 0; i < n; i++) {
            int temp = temperatures[i];
            while (!s.empty() && s.top().temperature < temp) {
                auto info = s.top(); s.pop();
                results[info.index] = i - info.index;
            }
            s.push(DateInfo(temperatures[i], i));
        }
        return results; // TC: O(n), SC: O(n)
    }
};