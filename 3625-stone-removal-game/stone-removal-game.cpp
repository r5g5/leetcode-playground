class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToBeRemoved = 10;
        bool isAliceTurn = true;

        while (n >= stonesToBeRemoved) {
            n -= stonesToBeRemoved;
            isAliceTurn = !isAliceTurn;
            stonesToBeRemoved--;
        }

        return !isAliceTurn; // TC: O(1), SC: O(1)
    }
};