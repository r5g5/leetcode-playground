class Solution {
    public String mergeAlternately(String word1, String word2) {
        StringBuilder s = new StringBuilder();
        final int len1 = word1.length();
        final int len2 = word2.length();
        int i = 0, j = 0;
        while (i < len1 && j < len2) {
            s.append(word1.charAt(i));
            s.append(word2.charAt(j));
            i++; j++;
        }

        while (i < len1) {
            s.append(word1.charAt(i++));
            // i++;
        }

        while (j < len2) {
            s.append(word2.charAt(j++));
            // j++;
        }

        return s.toString();
    }
}