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
    ListNode* removeElements(ListNode* root, int val) {
         ListNode *dummy = new ListNode(-1);
        dummy->next = root;
         ListNode *prev = dummy;
            while(root != NULL) {
                if(root->val == val) {
                    ListNode* toDelete = root;
                    prev->next = root->next;
                    root = root->next;   
                    delete toDelete;
                }
                else {
                    prev = root;
                    root = root->next;
                }
            }
        return dummy->next;
        }
};