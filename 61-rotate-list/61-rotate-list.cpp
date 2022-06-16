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
    int Length(ListNode *head) {
        ListNode *curr = head;
        int cnt = 0;
        while(curr != NULL) {
            curr = curr->next;
            cnt+=1;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode *newHead = NULL,*last = NULL,*curr = head;
        int i = 1;
        int len = Length(head);
        if(len == 0) return head;
        k = (k%len);
        if(k == 0) return head;
        
        while(curr != NULL) {
            if(i > k) {
                newHead = (newHead == NULL ? head : newHead->next);
            }
            last = curr;
            curr = curr->next;
            i += 1;
        }
        
        if(newHead == NULL) return head;
        
        ListNode *start = newHead->next;
        
        last->next = head;
        newHead->next = NULL;
        return start;
        
    }
};