class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string nextStr;
            for (int groupId = 0, n = s.size(); groupId < n; groupId += k) {
                string tmp = s.substr(groupId, k);
                int sum = accumulate(tmp.begin(), tmp.end(), 0, [&] (int sum, char digit) {
                    return sum += (digit - '0');
                });
                nextStr += to_string(sum);
            }
            s = nextStr;
        }
        return s; 
    }
};