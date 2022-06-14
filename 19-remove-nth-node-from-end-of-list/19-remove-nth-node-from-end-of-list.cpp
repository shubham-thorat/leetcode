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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        ListNode *current = head;
        int count = 0;
        while(current != NULL) {
            count++;
            current = current->next;
        }
        
        if(count == n) {
            ListNode *toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }
        
        count = count - n;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        while(count > 1) {
            head = head->next;
            count--;
        }
        ListNode *toDelete = head->next;
        head->next = head->next->next;
        delete toDelete;
        return dummy->next;
    }
};