class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missElements;
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        unordered_set<int> s;
        for (const auto& num : nums) {
            s.insert(num);
        }

        for (int i = l; i <= r; i++) {
            if (s.find(i) == s.end()) {
                missElements.push_back(i);
            }
        }

        return missElements; // TC: O(n), SC: O(n)
    }
};