class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i);
            bool hasChange = false, valid = true;
            for (auto& c : s) {
                if (c == '3' || c == '4' || c == '7') {
                    valid = false;
                    break;
                }
                else if (c == '2' || c == '5' || c == '6' || c == '9') {
                    hasChange = true;
                }
            }
            if (valid && hasChange)
                ++ans;
        }
        return ans;
    }
};