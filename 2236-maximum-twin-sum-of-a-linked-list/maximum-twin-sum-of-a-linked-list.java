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
        Deque<Integer> st = new ArrayDeque<>();
        var curr = head;
        while (curr != null) {
            st.push(curr.val);
            curr = curr.next;
        }
        int n = st.size() / 2;
        curr = head;
        int maxSum = Integer.MIN_VALUE;
        while (n > 0) {
            int twin = st.pop();
            maxSum = Math.max(maxSum, twin + head.val);
            head = head.next;
            n--;
        }
        return maxSum; // TC: O(n), SC: O(n)
    }
}