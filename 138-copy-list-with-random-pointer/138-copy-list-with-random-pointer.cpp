/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> pointers;
        
        Node *curr = head;
        Node *dummy = new Node(-1);
        Node *newHead = dummy;
        
        while(curr != NULL) {
            
            newHead->next = new Node(curr->val);
            pointers[curr] = newHead->next;
            curr = curr->next;
            newHead = newHead->next;
        }
        
        curr = head;
        newHead = dummy->next;
        while(curr != NULL) {
            if(curr->random != NULL) {
                newHead->random = pointers[curr->random];
            }
            curr = curr->next;
            newHead = newHead->next;
        }
        return dummy->next;
    }
};