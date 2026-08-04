class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missElements;
        sort(nums.begin(), nums.end());
        for (int i = 1, n = nums.size(); i < n; i++) {
            int l = nums[i-1], r = nums[i];
            for (int k = l + 1; k < r; k++) {
                missElements.push_back(k);
            }
        }
        return missElements; // TC: O(nlogn), SC: O(1) [not considering output as part of complexity; sorting algorithm]
    }
};