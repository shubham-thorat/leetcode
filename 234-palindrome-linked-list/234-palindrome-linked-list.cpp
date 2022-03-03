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
    ListNode *findMid(ListNode *head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }  
        return slow;
    }
    ListNode* reverse(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *curr = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return curr;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode *mid = findMid(head);
        if(mid == NULL) return true;
        ListNode *second = reverse(mid->next);
        mid->next = NULL;
        
        while(head != NULL && second != NULL){
            if(head->val != second->val) return false;
            head = head->next;
            second = second->next;
        }
        return true;
    }
};