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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes;
        ListNode *curr = headA;
        while(curr != NULL){
            nodes.insert(curr);
            curr = curr->next;
        }
        
        while(headB != NULL){
            if(nodes.find(headB) != nodes.end()) return headB;
            headB = headB->next;
        }
        return NULL;
    }
};