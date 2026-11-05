class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (const auto& i : arr1) {
            bool isValid = true;
            for (const auto& j : arr2) {
                const int distance = abs(i - j);
                if (distance <= d) {
                    isValid = false;
                    break;
                }
            }
            ans = (isValid ? ans + 1 : ans);
        }
        return ans; // TC: O(n.m) [n & m are the lengths of the arrays], SC: O(1)
    }
};