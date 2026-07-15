class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        /*
        NOTE: sum of first n odd numbers = n^2
        sum of first n even numbers = n^2 + n
        From euclidean algorithms, gcd(a, b) = gcd(b, a % b); a > b
        ====
        gcd(n^2 + n, n^2) = gcd(n^2, n)
        gcd(n^2, n) = gcd(n, 0) => n
        */
        return n; // TC: O(1), SC: O(1)
    }
};