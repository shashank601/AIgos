class Node {
public:
    list<pair<int,int>> ls;
    int freq;
    Node* next;
    Node* prev;

    Node(int f) : freq(f), next(nullptr), prev(nullptr) {}
};

class LFUCache {
public:
    unordered_map<int, Node*> buck;
    unordered_map<int, list<pair<int,int>>::iterator> lst;
    int sz;
    int cap;

    Node *head, *tail;

    LFUCache(int capacity) {
        sz = 0;
        cap = capacity;

        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;  
    }

    void insertNodeAtFront(Node* node) {
        int newFreq = node->freq + 1;
        Node* newNode = new Node(newFreq);

        newNode->next = node->next;
        node->next = newNode;  
        newNode->next->prev = newNode;
        newNode->prev = node;
    }
    
    void removeNode(Node* node) {
        node->next->prev = node->prev;    
        node->prev->next = node->next;   
        delete node; 
    }

    void promote(int key, int value) {
        Node* node = buck[key];
        auto iter = lst[key];

        node->ls.erase(iter);

        if (node->next->freq != node->freq + 1) {
            insertNodeAtFront(node);
        } 

        Node* old = node;

        
        node = node->next;

        node->ls.push_back({key, value});
        buck[key] = node;
        lst[key] = --node->ls.end();
        

        if (old->ls.empty()) {
            removeNode(old);    
        }

    }

    void evict() {
        if (tail->prev == head) return;
        sz--;

        Node* target = head->next;

        auto iter = target->ls.begin();
        int key = iter->first;
        target->ls.erase(iter);

        if (head->next->ls.empty()) removeNode(head->next);

        buck.erase(key);
        lst.erase(key);
    }

    
    
    int get(int key) {
        if (!buck.count(key)) {
            return -1;
        }
        int value = lst[key]->second;
        promote(key, value);
        return value;
    }
    
    void put(int key, int value) {
        if (!buck.count(key)) {
            if (sz == cap) {
                evict();
            }

            if (head->next->freq != 1) {
                insertNodeAtFront(head);
            }

            Node* node = head->next;

            node->ls.push_back({key, value});
            sz++;
            
            buck[key] = node;
            lst[key] = --node->ls.end();
            return;
        }
        promote(key, value);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



===========
mp.erase(key);                  // erase from map using key
mp.erase(it);                   // erase from map using iterator

lst.remove(val);                // erase all occurrences of value from list
lst.erase(it);                  // erase from list using iterator

===========

4 helpers

insert at fornt
evict   <-- form head not tail (LF)
removeNode       <-- just a optimization
promote  <-- most imp


==========

i was missing sz inc frequently in all atempts

used rBegin() insetad of --end()   they both have diff data type and for forward ptr use end()

mp uses erase
and list use remove for value and erase for iter


dont forget to return value in get

in evict do cleanup from map

===========


freq buck + list and maps for faster access
