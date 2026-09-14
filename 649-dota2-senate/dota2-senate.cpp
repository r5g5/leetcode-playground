class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiantQueue, direQueue;
        for (int i = 0, n = senate.size(); i < n; i++) {
            if (senate[i] == 'R') radiantQueue.push(i);
            else direQueue.push(i);
        }
        while (!radiantQueue.empty() && !direQueue.empty()) {
            int radiantIdx = radiantQueue.front(); radiantQueue.pop();
            int direIdx = direQueue.front(); direQueue.pop();

            if (radiantIdx < direIdx) {
                radiantQueue.push(radiantIdx + senate.size());
            } else {
                direQueue.push(direIdx + senate.size());
            }
        }

        return radiantQueue.empty() ? "Dire" : "Radiant"; // TC: O(n), SC: O(n)
    }
};