class Solution {
    public boolean isSubsequence(String s, String t) {
        if (s.isEmpty() && t.isEmpty()) return true;
        final int m = s.length(), n = t.length();
        for (int i = 0; i < n; i++) {
            int j = 0, tmp = i;
            while ((tmp < n) && (j < m)) {
                if (s.charAt(j) == t.charAt(tmp)) {
                    j++; tmp++;
                } else {
                    tmp++;
                }
            }
            if (j == m)
                return true;
        }
        return false;
    }
}