class Solution {
    public static final int NO_OF_CHARACTERS = 26;
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder s = new StringBuilder();
        for (var word : words) {
            int totalWeight = 0;
            for (var c : word.toCharArray()) {
                int weight = weights[(int) c - (int) 'a'];
                totalWeight += weight;
            }
            totalWeight %= NO_OF_CHARACTERS;
            char newChar = (char) ('z' - totalWeight);
            s.append(newChar);
        }
        return s.toString();
    }
}