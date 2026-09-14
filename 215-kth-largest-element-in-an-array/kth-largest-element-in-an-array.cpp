class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (const int i : nums) {
            q.push(i);
        }
        while (--k > 0) {
            q.pop();
        }
        return q.top(); // TC: O(n.logk), SC: O(n)
    }
};