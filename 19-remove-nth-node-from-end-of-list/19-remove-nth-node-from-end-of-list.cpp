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

#define null NULL
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          ListNode * after=head;
        ListNode * before=head;
        
        while(n--)
            after=after->next;
        if(!after)
            return head->next;
        while(after->next)
        {
            after=after->next;
            before=before->next;
        }
        before->next=before->next->next;
        
        return head;
                
    }
};