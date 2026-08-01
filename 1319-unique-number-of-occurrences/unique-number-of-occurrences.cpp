class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occCntMap;
        for (const int num : arr) {
            occCntMap[num]++;
        }
        unordered_set<int> s;
        for (auto& kvp : occCntMap) {
            if (s.find(kvp.second) == s.end()) {
                s.insert(kvp.second);
                continue;
            }
            return false;
        }
        return true; // TC: O(n), SC: O(n)
    }
};