class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest = INT_MIN, secondLargest = INT_MIN;

        for (const auto num : nums) {
            if (num > largest) {
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest) {
                secondLargest = num;
            }
        }

        return (largest - 1) * (secondLargest - 1); // TC: O(n), SC: O(1)
    }
};