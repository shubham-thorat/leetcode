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
    ListNode *rotateByOne(ListNode *head) {
        ListNode *curr = head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *prev = NULL;
        while(curr != NULL && curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        
        dummy->next = curr;
        curr->next = head;
        prev->next = NULL;
        return dummy->next;
    }
    int Length(ListNode *head) {
        
        ListNode *curr = head;
        int cnt = 0;
        while(curr != NULL) {
            curr = curr->next;
            cnt++;
            }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = Length(head);
        if(len == 0) return NULL;
        k = (k%len);
        
        for(int i=0;i<k;i++) {
            head = rotateByOne(head);
        }
        return head;
    }
};