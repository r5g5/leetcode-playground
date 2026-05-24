class Solution {
    private boolean isVowel(char c) {
        return "aeiouAEIOU".indexOf(c) >= 0;
    }
    public String reverseVowels(String s) {
        var charArr = s.toCharArray();
        int left = 0, right = s.length() - 1;
        while (left < right) {
            while (left < right && !isVowel(charArr[left])) left++;
            while (right > left && !isVowel(charArr[right])) right--;

            if (left < right) {
                char tmp = charArr[left];
                charArr[left] = charArr[right];
                charArr[right] = tmp;
            }

            left++;
            right--;
        }

        return new String(charArr); // TC: O(n), SC: O(n)
    }
}