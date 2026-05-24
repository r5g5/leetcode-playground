class Solution {
    private Boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); 
    }
    public String reverseVowels(String s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isVowel(s.charAt(i))) i++;
            while (j > i && !isVowel(s.charAt(j))) j--;
            if (i < j) {
                // swap them
                var sb = new StringBuilder(s);
                char tmp = s.charAt(i);
                sb.setCharAt(i, s.charAt(j));
                sb.setCharAt(j, tmp);
                s = sb.toString();
                i++; j--;
            }
        }
        return s; // TC: O(n^2), SC: O(n)
    }
}