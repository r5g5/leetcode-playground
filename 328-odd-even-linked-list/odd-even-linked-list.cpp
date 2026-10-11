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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr)
            return head;
            
        ListNode* oddTr = head;
        ListNode* evenTr = head->next;
        ListNode* split = evenTr;

        while (evenTr && oddTr) {
            if (evenTr->next == nullptr)
                break;
            oddTr->next = evenTr->next;
            oddTr = oddTr->next;
            evenTr->next = oddTr->next;
            evenTr = evenTr->next;
        }

        oddTr->next = split;

        return head; // TC: O(n), SC: O(1)
    }
};