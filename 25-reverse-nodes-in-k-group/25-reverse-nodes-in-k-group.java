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
    boolean isSufficientNode(ListNode head,int k){
        ListNode curr = head;
        while(k > 0 && curr != null){
            curr = curr.next;
            k--;
        }
        return (k == 0);
    }
    ListNode reverseGroup(ListNode head,int k){
        if(!isSufficientNode(head,k)){
            return head;
        }
        
        ListNode curr = head;
        ListNode start = head;
        ListNode prev = null;
        for(int i=1;i<=k;i++){
            ListNode nxt = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nxt;
        }
        
        start.next = reverseGroup(curr,k);
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        
        return reverseGroup(head,k);
    }
}