class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int smallestOne = 1e8, smallestTwo = 1e8, totalSum = 0;
        for (const int& num : nums) {
            totalSum += num;
            if (num % 3 == 1) {
                smallestTwo = min(smallestTwo, num + smallestOne);
                smallestOne = min(smallestOne, num);
            } else if (num % 3 == 2) {
                smallestOne = min(smallestOne, num + smallestTwo);
                smallestTwo = min(smallestTwo, num);
            }
        }

        if (totalSum % 3 == 0) {
            return totalSum;
        } else if (totalSum % 3 == 1) {
            return totalSum - smallestOne;
        } else {
            return totalSum - smallestTwo;
        }
    }
};