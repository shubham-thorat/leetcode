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
    public ListNode swapPairsWithRecursion(ListNode head){
        if(head == null || head.next == null){
            return head;
        }
        ListNode first = head;
        ListNode second = head.next;
        first.next = swapPairsWithRecursion(head.next.next);
        second.next = first;
        return second;
    }
    public ListNode swapPairs(ListNode head) {
//         ListNode start = new ListNode(-1);
//         ListNode curr = start;
        
//         while(head != null && head.next != null){
//             ListNode first = head;
//             ListNode second = head.next;
//             head = head.next.next;
            
//             second.next = first;
//             curr.next = second;
//             curr = first;
//             // curr = curr.next.next;
//         }
        
//         if(head != null){
//             curr.next = head;
//             curr.next.next = null;
//         }
//         else curr.next = null;
//         return start.next;
        
        return swapPairsWithRecursion(head);
        
    }
}