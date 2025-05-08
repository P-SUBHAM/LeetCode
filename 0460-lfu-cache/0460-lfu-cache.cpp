// Approach 1:
// cacheMAp key : DLLNode
// freq mapped DLL freq : headDLL->Node1->Node2->tailDLL
// 4: head4 - node4-node5-node6 - tail4
// 2: head2 - node3 - tail2
// 1: head1 - node1-node2 - tail1
// main function get, put
// helper function : UpdateFreq, removeDLLNode, insertDLLNode
// get : gets key using cacheMap + updateFreq else -1
// put : if exists update val+freq else new node, if cap minfreq del
class LFUCache {
public:
    struct Node {
        int key = -1, val = -1,freq = 1;
        Node *prev = NULL, *next = NULL;
    };
    unordered_map<int,Node*> cacheMp;
    unordered_map<int,vector<Node*>> freqMp;
    int capacity = 0, minFreq = 1;
    LFUCache(int _capacity) {
        capacity = _capacity;
    }
    int get(int key) {
        if(cacheMp.find(key) == cacheMp.end()) return -1;
        Node *node = cacheMp[key];
        updateFreq(node);
        return node->val;
    }
    void put(int key, int value) {
        if(cacheMp.find(key) != cacheMp.end()) {
            Node *node = cacheMp[key];
            node->val = value;
            updateFreq(node); return;
        }
        else {
            Node *node = new Node;
            node->key = key;
            node->val = value;
            cacheMp[key] = node; capacity--;
            if(capacity < 0) {
                Node *nodeToDel = freqMp[minFreq][0]->next;
                removeNode(nodeToDel);
                cacheMp.erase(nodeToDel->key);
                capacity++;
            }
            minFreq = 1;
            addNode(node);
        }
    }
    void updateFreq(Node *node) {
        removeNode(node);
        if(freqMp[node->freq][0]->next == freqMp[node->freq][1]) {
            freqMp.erase(node->freq);
            if(minFreq == node->freq) minFreq++;
        }
        node->freq++; 
        addNode(node);
    }
    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNode(Node *node) {
        if(freqMp.find(node->freq) == freqMp.end()) {
            Node *head = new Node;
            Node *tail = new Node;
            head->next = tail;
            tail->prev = head;
            freqMp[node->freq] = {head,tail};
        }
        node->next = freqMp[node->freq][1];
        node->prev = freqMp[node->freq][1]->prev;
        freqMp[node->freq][1]->prev->next = node;
        freqMp[node->freq][1]->prev = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */