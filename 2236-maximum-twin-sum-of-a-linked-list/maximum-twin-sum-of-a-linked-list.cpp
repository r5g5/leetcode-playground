/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // push all node to vector
        vector<int> nodeList;
        while (head) {
            nodeList.emplace_back(head->val);
            head = head->next;
        }
        int i = 0, j = nodeList.size() - 1, maxTwinSum = 0;
        while (i < j) {
            int sum = nodeList[i] + nodeList[j];
            i++; --j;
            maxTwinSum = max(maxTwinSum, sum);
        }
        return maxTwinSum; // TC: O(n), SC: O(n)
    }
};