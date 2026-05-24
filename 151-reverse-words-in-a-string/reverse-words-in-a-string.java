class Solution {
    public String reverseWords(String s) {
        var words = s.trim().split("\\s+");
        for (int i = 0, j = words.length - 1; i < j; i++, j--) {
            var tmp = words[i];
            words[i] = words[j];
            words[j] = tmp;
        }
        return String.join(" ", words);
    }
}