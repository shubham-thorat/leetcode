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
    
    int len(ListNode *head) {
        if(head == NULL) return 0;
        return len(head->next) + 1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL) return NULL;
        if(len(head) < k) return head;
        ListNode *curr = head;
        ListNode *prev = NULL;
        int count = 0;
        while(count < k && curr != NULL) {
            ListNode *nxt = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = nxt;
            count++;
        }
        
        head->next  = reverseKGroup(curr,k);
        return prev;
    }
};
