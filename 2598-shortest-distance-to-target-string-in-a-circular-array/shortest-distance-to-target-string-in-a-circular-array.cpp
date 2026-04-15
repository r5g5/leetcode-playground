class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int curr = startIndex, steps = 0, size = words.size();
        bool found = false;
        int ans = INT_MAX;
        do {
            if (words[curr] == target) {
                found = true;
                ans = min(ans, min(steps, size- steps));
            }
            curr = (curr + 1) % size;
            steps++;
            cout << curr << ' ' << size << ' ' << steps << endl;
        } while (curr != startIndex);
        return found ? ans : -1;
    }
};