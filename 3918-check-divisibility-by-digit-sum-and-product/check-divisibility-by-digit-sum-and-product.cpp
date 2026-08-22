class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int tmp = n;
        while (tmp > 0) {
            sum += (tmp % 10);
            product *= (tmp % 10);
            tmp /= 10;
        }

        return (n % (sum + product)) == 0; // TC: O(log10(n)), SC: O(1)
    }
};