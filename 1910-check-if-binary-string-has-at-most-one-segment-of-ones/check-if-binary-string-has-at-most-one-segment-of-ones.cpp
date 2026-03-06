class Solution {
public:
    bool checkOnesSegment(string s) {
        auto it = find(s.begin(), s.end(), '0');
        if (it == s.end())
            return true;
        for (; it != s.end(); it++) {
            if (*it == '1')
                return false;
        }
        return true;
    }
};