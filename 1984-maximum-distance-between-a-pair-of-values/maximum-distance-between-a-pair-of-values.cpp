class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++) {
            auto it = upper_bound(nums2.begin(), nums2.end(), nums1[i], greater<int>());
            if (!(it == nums2.begin())) {
                int j = (--it) - nums2.begin();
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};