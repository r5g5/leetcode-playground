class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> count;
        for (const auto& num : nums1) {
            count.insert(num);
        }
        for (const auto& num : nums2) {
            if (count.find(num) != count.end())
                return num;
        }
        return -1;
    }
};