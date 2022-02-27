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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode *start = new ListNode(-200);
        ListNode *curr = start,*prev = NULL;
        
        while(head != NULL){
            if(prev != NULL && head->val == prev->val){
                head = head->next;
            }
            else {
                curr->next = head;
                prev = head;
                head = head->next;
                curr = curr->next;
            }
        }
        curr->next = NULL;
        return start->next;
        
    }
};