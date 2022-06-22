#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    private:
        class Node {
            public:
            int key,value;
            Node *next,*prev;
            Node(int key,int value) {
                this->key = key;
                this->value = value;
                next = prev = nullptr;
            }
        };

        unordered_map<int,Node*> cache;
        Node *head,*tail;
        int capacity,size;

        void deleteNode(Node *current) {
            Node *prevNode = current->prev;
            prevNode->next = current->next;
            current->next->prev = prevNode;
            cache.erase(current->key);
        }
        void addNodeAtStart(int key,int value) {
            Node *temp = new Node(key,value);

            temp->next = head->next;
            head->next->prev = temp;

            head->next = temp;
            temp->prev = head;

            cache[key] = temp;
        }
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
            size = 0;
            
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
        }

        void put(int key,int value) {

            if(cache.find(key) == cache.end()) {
                if(size == capacity) {
                    deleteNode(tail->prev);
                    size--;
                }
                addNodeAtStart(key,value);
                size++;
            }
            else {
                Node *temp = cache[key];
                deleteNode(temp);
                addNodeAtStart(key,value);
            }
        }

        int get(int key) {
            if(cache.find(key) == cache.end()) {
                return -1;
            }

            Node *current = cache[key];
            int k = current->key;
            int v = current->value;
            deleteNode(current);
            addNodeAtStart(k,v);
            return v;
        }
};