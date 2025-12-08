class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int c = i * i + j * j;
                double sq = sqrt(c);
                if (ceil(sq) == floor(sq) && sq <= n)
                    ++cnt;
            }
        }
        return cnt;
    }
};