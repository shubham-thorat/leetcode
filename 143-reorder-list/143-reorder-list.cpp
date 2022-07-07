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
    void reorderList(ListNode* head) {
        
        //find middle of LL
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Reverse from mid till end
        ListNode* prev = NULL;
        ListNode* curr = slow;
        ListNode* nextnode;
        while(curr!=NULL){
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        //Reorder 
        ListNode* head1 = new ListNode(-1);
        ListNode* temp = head1;
        fast = head;
        while(prev!=NULL){
            if(fast==prev){
                temp->next = fast;
                temp = temp->next;
                break;
            }
            temp->next = fast;
            fast = fast->next;
            temp = temp->next;
            
            temp->next = prev;
            temp = temp->next;
            prev = prev->next;
        }
        temp->next = NULL;
        head = head1->next;
    }
};