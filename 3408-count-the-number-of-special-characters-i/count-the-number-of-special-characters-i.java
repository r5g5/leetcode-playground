class Solution {
    public int numberOfSpecialChars(String word) {
        var set = new HashSet<Character>();
        for (char letter : word.toCharArray()) {
            set.add(letter);
        }
        int count = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            char lowerChar = c;
            char upperChar = Character.toUpperCase(lowerChar);
            if (set.contains(lowerChar) && set.contains(upperChar))
                ++count;
        }
        return count;
    }
}