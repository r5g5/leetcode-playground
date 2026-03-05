class Solution {
public:
    int minOperations(string s) {
        int startWithZero = 0, startWithOne = 0;
        char curr = '0';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != curr)
                startWithZero++;
            
            curr = (curr == '0') ? '1' : '0';
        }
        curr = '1';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != curr) {
                startWithOne++;
            }
            curr = (curr == '0') ? '1' : '0';
        }
        return min(startWithOne, startWithZero);
    }
};