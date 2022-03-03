/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* origin(ListNode *a,ListNode *b){
        while(a != NULL && b != NULL && a != b){
            a = a->next;
            b = b->next;
        }
        return a;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == headB) return headA;
        ListNode *a = headA;
        ListNode *b = headB;
        
        while(a != NULL && b != NULL){
            a = a->next;
            b = b->next;
        }
        int count = 0;
        if(a != NULL){
            while(a != NULL) { count++; a=a->next; }
            b = headB;
            a = headA;
            while(count--) a = a->next;
            return origin(a,b);
        }
        else {
            
            while(b != NULL) { count++; b=b->next; }
            b = headB;
            a = headA;
            while(count--) b = b->next;
            return origin(a,b);
        }
        
        // return NULL;
    }
};