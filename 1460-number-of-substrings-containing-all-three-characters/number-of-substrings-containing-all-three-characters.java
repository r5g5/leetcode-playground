class Solution {
    public int numberOfSubstrings(String s) {
        int[] last = {-1, -1, -1};
        int ans = 0;

        for (int r = 0; r < s.length(); r++) {
            last[s.charAt(r) - 'a'] = r;
            int minLast = Math.min(last[0], Math.min(last[1], last[2]));
            ans += minLast + 1;
        }
        
        return ans;
    }
}