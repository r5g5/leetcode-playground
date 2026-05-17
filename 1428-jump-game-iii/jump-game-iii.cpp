class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if ((start >= 0) && (start < arr.size()) && (arr[start] >= 0)) {
            if (arr[start] == 0)
                return true;
            else {
                const int val = arr[start];
                arr[start] = -1;
                return canReach(arr, start - val) || canReach(arr, start + val);
            }
        }
        return false;
    }
};