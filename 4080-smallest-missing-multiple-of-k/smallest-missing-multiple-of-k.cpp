class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> kSet;
        for (int num : nums) {
            if (num % k == 0) {
                kSet.insert(num);
            }
        }
        int multK = k;
        while (kSet.count(multK)) {
            multK += k;
        }
        return multK; // TC: O(n), SC: O(K)
    }
};