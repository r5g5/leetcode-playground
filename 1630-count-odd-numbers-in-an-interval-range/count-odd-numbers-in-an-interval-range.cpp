class Solution {
private:
    int getOddBtwn(const int low, const int high, const int rn) {
        if (low & 1) {
            return (rn / 2);
        }
        return ceil(rn / 2.0);
    }
public:
    int countOdds(int low, int high) {
        int noInBtwn = high - low - 1;
        if (noInBtwn < 0) {
            return (low & 1);
        } else if (noInBtwn == 0) {
            return (low & 1) + (high & 1);
        } else if (noInBtwn == 1) {
            return (low & 1) + ((low + 1) & 1) + (high & 1);
        } else {
            if (noInBtwn & 1) {
                return (low & 1) + (high & 1) + getOddBtwn(low, high, noInBtwn);
            } else {
                return (low & 1) + (high & 1) + (noInBtwn / 2);
            }
        }
        return -1;
    }
};