/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        if(head == null || head.next == null) return null;
        
        ListNode slow = head;
        ListNode fast = head.next;
        
        while(slow != fast && fast != null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;
        }
        
        if(slow != fast) return null;
        slow = head;
        fast = fast.next;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}