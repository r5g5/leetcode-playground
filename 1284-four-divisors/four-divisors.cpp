class Solution {
    inline const pair<int, int> getNoOfDivAndSum(const int num) {
        int cnt = 0, sum = 0;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                if (num / i == i) {
                    cnt++;
                    sum += i;
                } else {
                    cnt += 2;
                    sum += i; 
                    sum += (num / i);
                }
            }
        }
        return {cnt, sum};
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (const int& num : nums) {
            auto noSum = getNoOfDivAndSum(num);
            if (noSum.first == 4) {
                ans += noSum.second;
            }
        }
        return ans;
    }
};