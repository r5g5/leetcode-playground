class Solution {
    private boolean isValid(String s1, String s2, int k) {
        final int l1 = s1.length(), l2 = s2.length();
        if (l1 % k > 0 || l2 % k > 0)
            return false;
        
        String base = s1.substring(0, k);

        return s1.replace(base, "").isEmpty() && s2.replace(base, "").isEmpty();
    }
    public String gcdOfStrings(String str1, String str2) {
        int len1 = str1.length(), len2 = str2.length();

        for (int i = Math.min(len1, len2); i >= 1; i--) {
            if (isValid(str1, str2, i)) {
                return str1.substring(0, i);
            }
        }

        return "";
    }
}