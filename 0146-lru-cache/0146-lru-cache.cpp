class LRUCache {
public:
    // head <-> n1 <-> n2 <-> tail
    // class node 
    class node {
        public:
        int key, val;
        node *next, *prev;
        node(int _key, int _val) {
            key = _key; val = _val;
        }
    };
    // map for caching data, capacity, DLL->(head,tail)
    unordered_map<int,node*> mpp;
    int cap;
    node *head = new node(-1,-1); 
    node *tail = new node(-1,-1);
    // initialize LRUCache
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    // extra helper func -> delete, insert at head
    void addnode(node* newnode) {
        newnode->next = head->next;
        head->next->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
        cap--;
    }
    // delete node at any location
    void deletenode(node* delnode) {
        delnode->next->prev = delnode->prev;
        delnode->prev->next = delnode->next;
        cap++;
    }
    // default func implementaion -> get,put
    // get val from key map, if not there -1
    // but after getting also move it to head
    int get(int key) {
        if(mpp.find(key)==mpp.end()) {
            return -1;
        }
        deletenode(mpp[key]);
        addnode(mpp[key]);
        return mpp[key]->val;
    }
    
    void put(int key, int value) {
        // key doesnt exists so add at head
        if(mpp.find(key) == mpp.end()) {
            // if cap is full remove last node(least recently used)
            if(cap == 0){
                node* todel = tail->prev;
                mpp.erase(todel->key);
                // cout<<" toa:"<<key;
                // cout<<" d:"<<todel->key;
                deletenode(todel);
                delete todel;
            }
            // add newnode at head
            node* newnode = new node(key,value);
            mpp[key] = newnode;
            addnode(newnode);
        }
        // update existing node
        else {
            node* existingNode = mpp[key];
            existingNode->val = value;
            deletenode(existingNode);
            addnode(existingNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */