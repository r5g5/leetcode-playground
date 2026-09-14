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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* tmp = head;
        int n = 0;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }
        if (n == 1) return nullptr;
        int mid = n / 2;
        tmp = head;
        for (int i = 0; i < mid - 1; i++) {
            tmp = tmp->next;
        }
        if (tmp->next == nullptr) {
            tmp = nullptr;
        } else 
            tmp->next = tmp->next->next;
        return head; // TC: O(n), SC: O(1)
    }
};