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
        ListNode* tmp = head;
        unordered_set<int> s;
        for (int& i : nums) {
            s.insert(i);
        }
        while (tmp != nullptr) {
            if (s.find(tmp->val) == s.end())
                break;
            tmp = tmp->next;
        }

        if (tmp == nullptr) {
            return nullptr;
        } else {
            ListNode* prev = tmp;
            ListNode* ans = prev;
            tmp = tmp->next;
            while (tmp != nullptr) {
                if (s.find(tmp->val) != s.end()) {
                    tmp = tmp->next;
                    prev->next = tmp;
                } else {
                    prev = prev->next;
                    tmp = tmp->next;
                }
            }
            return ans;
        }
    }
};