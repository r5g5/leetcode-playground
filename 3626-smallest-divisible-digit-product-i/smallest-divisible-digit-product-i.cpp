class Solution {
private:
    inline int getDigitProduct(int x) {
        int product = 1;
        while (x) {
            product *= (x % 10);
            x /= 10;
        }
        return product;
    }
public:
    int smallestNumber(int n, int t) {
        while (true) {
            if (getDigitProduct(n) % t == 0) break;
            ++n;
        }
        return n; // TC: O(1), SC: O(1)
    }
};