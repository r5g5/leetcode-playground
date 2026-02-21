class Solution {
private:
    bool isPrime(const int x) {
        if (x == 1) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for (int num = left; num <= right; num++) {
            if (isPrime(__builtin_popcount(num)))
                ++cnt;
        }
        return cnt;
    }
};