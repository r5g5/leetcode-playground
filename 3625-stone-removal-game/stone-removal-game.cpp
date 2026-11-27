class Solution {
public:
    bool canAliceWin(int n) {
        int stonesToBeRemoved = 10;
        int moves = 0;

        while (n >= stonesToBeRemoved) {
            n -= stonesToBeRemoved;
            stonesToBeRemoved--;
            moves++;
        }

        return (moves % 2) == 1; // TC: O(1), SC: O(1)
    }
};