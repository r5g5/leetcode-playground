class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        int[] freq = new int[100001];
        for (int asteroid : asteroids) {
            freq[asteroid]++;
        }
        long sum = mass;
        for (int a = 1; a <= 100000; a++) {
            while (freq[a]-- > 0) {
                if (sum < a)
                    return false;
                sum += a;
            }
        }
        return true; // TC: O(n), SC: O(n)
    }
}