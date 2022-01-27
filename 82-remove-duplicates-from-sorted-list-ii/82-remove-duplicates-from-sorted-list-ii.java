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
        if(head == null) return head;
        ListNode start = new ListNode(-1);
        ListNode curr = start;
        ListNode prev = null;
        while(head != null && head.next != null){
            
            if(head.val != head.next.val && (prev == null || prev.val != head.val)){
                curr.next = head;
                prev = head;
                head = head.next;
                curr = curr.next;
                prev.next = null;
                curr.next = null;
            }
            else {   
                
                prev = head;
                // System.out.println(head.val);
                head = head.next;
                
                prev.next = null;
            }
        }
        if(prev == null || (prev.val != head.val)){
            curr.next = head;
            curr.next.next = null;
        }
        return start.next;
    }
}