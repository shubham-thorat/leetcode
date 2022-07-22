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
        if(root == NULL) return NULL;
        
        if(root->val == val) {
            return removeElements(root->next,val);
        }
        else {
            root->next = removeElements(root->next,val);
            return root;
        }
    }
};