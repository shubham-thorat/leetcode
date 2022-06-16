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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0) return head;
        
        ListNode *last = head;
        int len = 1;
        
        while(last->next != NULL) {
            last = last->next;
            len++;
        }
        
        k = (k%len);
        // if(k == 0) return head;
        
        ListNode *end = head;
        k = len - k - 1;
        
        while(k--) {
            end = end->next;
        }
        last->next = head;
        ListNode *newHead = end->next;
        end->next = NULL;
        return newHead;
    }
};