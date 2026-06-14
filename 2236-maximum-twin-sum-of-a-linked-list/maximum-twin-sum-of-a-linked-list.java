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
        var list = new ArrayList<Integer>();
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }
        int i = 0;
        int j = list.size() - 1;
        int ans = Integer.MIN_VALUE;
        while (i < j) {
            ans = Math.max(ans, list.get(j) + list.get(i));
            i++;
            j--;
        }
        return ans;
    }
}