class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if (digits[n-1] == 9) {
            int i = n - 1;
            for (; i >= 0; i--) {
                if (digits[i] == 9)
                    digits[i] = 0;
                else
                    break;
            }
            if (i < 0) {
                digits.insert(digits.begin(), 1);
            } else
                digits[i]++;
        } else {
            digits[n-1]++;
        }
        return digits;
    }
};