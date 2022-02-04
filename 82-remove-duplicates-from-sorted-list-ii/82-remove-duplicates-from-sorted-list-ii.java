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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode start = new ListNode(-1);
        ListNode curr = start;
        ListNode prev = null;
        while(head != null){
           if((prev == null || prev.val != head.val) && (head.next == null || head.next.val != head.val)){
               curr.next = head;
               curr = curr.next;
           }
            prev = head;
            head = head.next;
        }
        curr.next = null;
        return start.next;
    }
}