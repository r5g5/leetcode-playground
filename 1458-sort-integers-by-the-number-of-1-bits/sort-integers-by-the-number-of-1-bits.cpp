class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&] (const int numOne, const int numTwo) -> bool {
            int noOfOnesInFirst = __builtin_popcount(numOne);
            int noOfTwosInSecond = __builtin_popcount(numTwo);

            if (noOfOnesInFirst == noOfTwosInSecond)
                return numOne < numTwo;
            
            return noOfOnesInFirst < noOfTwosInSecond;
        });
        return arr;
    }
};