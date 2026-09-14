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
        const int mid = n / 2;
        ListNode* prev = nullptr;
        tmp = head;

        for (int i = 0; i < mid; i++) {
            prev = tmp;
            tmp = tmp->next;
        }

        if (prev == nullptr) return prev;

        if (tmp == nullptr) {
            prev->next = nullptr;
        } else {
            prev->next = tmp->next;
        }

        return head; // TC: O(n), SC: O(1)
    }
};