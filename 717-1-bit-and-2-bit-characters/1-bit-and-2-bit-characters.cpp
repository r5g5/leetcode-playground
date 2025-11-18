class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int idx = 0;
        for (idx = 0; idx < bits.size(); ) {
            if (idx == bits.size() - 1) {
                if (bits[idx] == 1)
                    return false;
                break;
            }
            if (idx == bits.size() - 2) {
                if (bits[idx] == 1)
                    return false;
                break;
             }
            if (bits[idx]) {
                idx += 2;
            } else {
                idx++;
            }
        }
        return true;
    }
};