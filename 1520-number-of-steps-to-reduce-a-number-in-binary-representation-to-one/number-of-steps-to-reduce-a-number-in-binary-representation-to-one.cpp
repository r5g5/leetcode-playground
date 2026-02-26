class Solution {
public:
    int numSteps(string s) {
        int steps = 0;

        bitset<501> bits(s);
        while (!((bits.count() == 1) && (bits[0] == 1))) {
            if (bits[0] == 1) {
                // odd case
                for (int i = 0; i<501; i++) {
                    if (bits[i] == 0) {
                        bits.set(i);
                        break;
                    } else {
                        bits.reset(i);
                    }
                }
            } else {
                // even case
                bits >>= 1;
            }
            ++steps;
        }
        return steps;
    }
};