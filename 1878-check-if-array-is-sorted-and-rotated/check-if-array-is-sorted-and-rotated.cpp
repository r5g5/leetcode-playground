class Solution {
public:
    bool check(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end()))
            return true;
        
        for (int i = 0, n = nums.size(); i < n; i++) {
            // first i elements at the back
            // final arr = [i + 1....n, 0...i]

            vector<int> tmp;
            // tmp.resize(n);
            tmp.insert(tmp.begin(), nums.begin() + i + 1, nums.end());
            tmp.insert(tmp.end(), nums.begin(), nums.begin() + i + 1);
            

            if (is_sorted(tmp.begin(), tmp.end()))  return true;
        }
        return false;
    }
};