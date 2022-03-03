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
    ListNode *curr;
    bool check(ListNode *head){
        if(head == NULL) return true;
        bool ispal = (check(head->next) && (head->val == curr->val));
        curr = curr->next;
        return ispal;
    }
    bool isPalindrome(ListNode* head) {
        curr = head;
        return check(head);
    }
};