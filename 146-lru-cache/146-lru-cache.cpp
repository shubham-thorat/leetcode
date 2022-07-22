class LRUCache {
public:
    class Node {
      public:
        int key;
        int value;
        Node *next,*prev;
        Node(int key,int value) {
            this->key = key;
            this->value = value;
        }
    };
    unordered_map<int,Node*> cache;
    Node *head,*tail;
    int capacity;
    int currCap = 0;
    LRUCache(int capacity) {
       head = new Node(0,0);
       tail = new Node(0,0);
       head->next = tail;
       tail->prev = head;
        
       this->capacity = capacity;
    }
    // [1,1]
    // back    front
   // ,[1,1],
    int get(int key) {
        if(cache.find(key) == cache.end()) {
            return -1;
        }
        else {
            int v = cache[key]->value;
            deleteNode(key);
            Node *temp = InsertAtFirst(key,v);
            cache[key] = temp;
            return v;
        }
    }
    Node* InsertAtFirst(int key,int value) {
        Node *temp = new Node(key,value);
        Node *nxt = head->next;
        
        head->next = temp;
        temp->prev = head;
        temp->next = nxt;
        nxt->prev = temp;
        return temp;
    }
    void deleteNode(int key) {
        Node *temp = cache[key];
        cache.erase(key);
        Node *pv = temp->prev;
        Node *nxt = temp->next;
        
        pv->next = nxt;
        nxt->prev = pv;
    }
    void put(int key, int value) {
        if(cache.find(key) == cache.end()) {
             if(currCap == capacity) {
                deleteNode(tail->prev->key);
                currCap--;
            }
            
            Node *temp = InsertAtFirst(key,value);
            cache[key] = temp;
            currCap++;
        }
        else {
           
            deleteNode(key);
            cache[key] = InsertAtFirst(key,value);
        }
    }
};
// back        front
// [2,6],[1,2]

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */