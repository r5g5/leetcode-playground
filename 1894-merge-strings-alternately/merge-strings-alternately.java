class Solution {
    public String mergeAlternately(String word1, String word2) {
        final int len1 = word1.length(), len2 = word2.length();
        var sb = new StringBuilder(len1 + len2);
        var i = 0;
        while (i < len1 || i < len2) {
            if (i < len1) sb.append(word1.charAt(i));
            if (i < len2) sb.append(word2.charAt(i));
            i++;
        }
        return sb.toString();
    }
}