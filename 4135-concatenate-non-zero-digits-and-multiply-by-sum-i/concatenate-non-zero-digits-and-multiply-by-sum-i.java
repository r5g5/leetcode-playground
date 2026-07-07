class Solution {
    public long sumAndMultiply(int n) {
        long x = 0, mult = 1, sum = 0;
        while (n > 0) {
            int last = n % 10;
            n /= 10;
            sum += last;
            if (last != 0) {
                x += (mult * last);
                mult *= 10;
            }
        }
        return x * sum; // TC: O(log10(n)), SC: O(1)
    }
}