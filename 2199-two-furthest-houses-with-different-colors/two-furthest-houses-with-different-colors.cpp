class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0, l = 0, r = colors.size() - 1;
        while (l <= r) {
            if (colors[l] != colors[r])
                break;
            // reduce rightmost index
            r--;
        }
        ans = max(ans, r - l);
        l = 0, r = colors.size() - 1;
        while (l <= r) {
            if (colors[l] != colors[r])
                break;
            // increase leftmost index
            l++;
        }
        return max(ans, r - l);
    }
};