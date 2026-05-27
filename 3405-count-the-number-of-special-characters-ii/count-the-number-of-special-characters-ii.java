class Solution {
    public int numberOfSpecialChars(String word) {
        var charToIdxMap = new HashMap<Character, Integer>();
        for (int i = 0; i < word.length(); i++) {
            var ch = word.charAt(i);
            if (Character.isUpperCase(ch) && !charToIdxMap.containsKey(ch)) {
                charToIdxMap.put(ch, i);
            }
        }
        int ans = 0;
        for (int i = word.length() - 1; i >= 0; i--) {
            var ch = word.charAt(i);
            var up = Character.toUpperCase(ch);
            if (Character.isLowerCase(ch) && charToIdxMap.containsKey(up)) {
                var idx = charToIdxMap.get(up);
                if (i < idx)
                    ++ans;
                charToIdxMap.put(up, -1);
            }
        }
        return ans;
    }
}