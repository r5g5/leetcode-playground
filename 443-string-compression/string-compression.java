class Solution {
    public int compress(char[] chars) {
        final int n = chars.length;
        int nextWriteIdx = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && chars[j] == chars[i]) {
                j++;
            }
            int cnt = j - i;
            if (cnt == 1) {
                chars[nextWriteIdx++] = chars[i];
            } else {
                chars[nextWriteIdx++] = chars[i];
                var tmp = Integer.toString(cnt);
                for (int k = 0; k < tmp.length(); k++) {
                    chars[nextWriteIdx++] = tmp.charAt(k);
                }
            }
            i = j;
        }
        return nextWriteIdx;
    }
}