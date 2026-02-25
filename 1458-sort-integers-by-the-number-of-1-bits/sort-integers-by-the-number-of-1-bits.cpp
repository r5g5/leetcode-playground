class Solution {
private:
    int findWeight(int num) {
        int weight = 0, mask = 1;
        while (num > 0) {
            if ((num & mask) > 0) {
                weight++;
                num ^= mask;
            } 
            mask <<= 1;
        }
        return weight;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this] (const int numOne, const int numTwo) -> bool {
            int wOne = findWeight(numOne);
            int wTwo = findWeight(numTwo);
            if (wOne == wTwo) {
                return numOne < numTwo;
            }
            return wOne < wTwo;
        });
        return arr;
    }
};