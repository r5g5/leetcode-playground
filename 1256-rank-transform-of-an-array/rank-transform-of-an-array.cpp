class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> numToRankMap;
        set<int> s;
        for (int num : arr) {
            s.insert(num);
        }
        int rank = 1;
        for (int num : s) {
            // cout << num << " is assigned rank: " << rank << endl;
            numToRankMap[num] = rank++;
        }
        for (int i = 0, n = arr.size(); i < n; i++) {
            arr[i] = numToRankMap[arr[i]];
        }

        return arr; // TC: O(nlogn), SC: O(n)
    }
};