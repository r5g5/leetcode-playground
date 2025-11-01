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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }

        unordered_set<int> elements;
        for (int& i : nums) {
            elements.insert(i);
        }

        ListNode* newLinkedList = new ListNode();
        ListNode* tmp = newLinkedList;
        for (int& i : v) {
            if (elements.find(i) == elements.end()) {
                ListNode* node = new ListNode(i);
                tmp->next = node;
                tmp = node;
            }
        }
        newLinkedList = newLinkedList->next;
        return newLinkedList;
    }
};