class Solution {
public:
    int binaryGap(int n) {
        string binary = bitset<30>(n).to_string();
        
        int prevOne = -1, ans = 0;
        for (int i = 0; i < 30; i++) {
            if (binary[i] == '1') {
                if (prevOne == -1) {
                    prevOne = i;
                } else {
                    ans = max(ans, i - prevOne);
                    prevOne = i;
                }
            }
        }

        return ans;
    }
};