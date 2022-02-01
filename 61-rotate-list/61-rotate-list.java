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
    
// 1 -> 2 ->


class Solution {
    int CountNode(ListNode head){
        ListNode curr = head;
        int val = 0;
        while(curr != null){
            curr = curr.next;
            val++;
        }
        return val;
    }
//     i,j 
        
//         i - k
//          j - var
//         last
    
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null) return head;
        int count = CountNode(head);
        k = k%count;
        ListNode slow= head,fast = head;
        int i = 0;
        ListNode lastfast = null;
        while(fast != null){
            if(i > k){
                    slow = slow.next;
            }
            lastfast = fast;
            fast = fast.next;
            i++;
        }
         
        if(slow.next == null){
            return head;
        }
        else {
            lastfast.next = head;
            ListNode t = slow.next;
            slow.next = null;
            return t;
        }
        
    }
}