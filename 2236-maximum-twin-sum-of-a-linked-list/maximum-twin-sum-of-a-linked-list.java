/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int pairSum(ListNode head) {
        int n = 0;
        ListNode tmp = head;
        while (tmp != null) {
            n++;
            tmp = tmp.next;
        }
        int mid = n / 2;
        int curr = 0;
        ListNode prev = null;
        boolean startReversing = false;
        tmp = head;
        while (tmp != null) {
            if (curr >= mid) {
                ListNode next = tmp.next;
                ListNode tmp2 = tmp;
                if (!startReversing) {
                    startReversing = true;
                    prev.next = null;
                    tmp2.next = null;
                } else {
                    tmp.next = prev;
                }
                prev = tmp2;
                if (next == null) break;
                tmp = next;
            } else {
                prev = tmp;
                tmp = tmp.next;
            }
            curr++;
        }
        assert tmp != null : "Unexpected";
        int ans = Integer.MIN_VALUE;
        ListNode tail = tmp;
        while (head != null && tail != null) {
            ans = Math.max(ans, head.val + tail.val);
            head = head.next;
            tail = tail.next;
        }
        return ans; // TC: O(n), SC: O(1)
    }
}