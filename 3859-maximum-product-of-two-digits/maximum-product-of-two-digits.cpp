class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;
        while (n > 0) {
            int last = n % 10;
            if (last > first) {
                second = first;
                first = last;
            } else if (last > second) {
                second = last;
            }
            n /= 10;
        }
        return first * second; // TC: O(log10(n)), SC: O(1)
    }
};