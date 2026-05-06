class Node {
public: 
    int key;
    int value;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), value(v) {
        next = nullptr;
        prev = nullptr;
    }
};                        <-- ;



class LRUCache {
public:
    int cap;
    int size;
    Node* head;
    Node* tail;

    unordered_map<int, Node*> lookup;
    
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->next = tail;
        tail->prev = head;
    }


    
    int get(int key) {
        if (lookup.count(key)) {
            Node* node = lookup[key];

            node->next->prev = node->prev;
            node->prev->next = node->next;

            node->next = head->next;
            head->next->prev = node;
            
            node->prev = head;
            head->next = node;

            return lookup[key]->value;

        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if (lookup.count(key)) {
            Node* node = lookup[key];

            node->next->prev = node->prev;
            node->prev->next = node->next;

            node->next = head->next;
            head->next->prev = node;
            
            node->prev = head;
            head->next = node;

            
            lookup[key]->value = value;


            return;
        }

        if (size == cap) {
            Node* evict = tail->prev;

            tail->prev = evict->prev;
            evict->prev->next = tail;

            
            lookup.erase(evict->key);
            delete evict;
            size--;
        }
        Node* node = new Node(key, value);


        node->next = head->next;
        head->next->prev = node;
        
        node->prev = head;
        head->next = node;

        lookup[key] = head->next;
        size++;
    }
};
==============

Mistakes.
  
* used Key instead of key (case sensitivity error)

* used remove() instead of erase() on unordered_map

* missed node->next->prev update during insertion (broke DLL)      <-- backward chain was broken

* fixed insertion in put but forgot same fix in get

* erased wrong key during eviction (used key instead of evict->key)
  
* map kept pointer to deleted node → dangling pointer → runtime crash

* update case didn’t move node to front (violates LRU rule)

* duplicated remove/insert logic in multiple places → inconsistent fixes     <-- i intenitionally didnt created a helper (move node at head) i was not interested

* used lookup[key] instead of node (relies on indirect pointer, fragile)

Execution cue: write remove(node) and insert_front(node) once and reuse everywhere.

============

one global dll
one global map for O1 access

[{k,N}, {k,N}, {k,N}, {k,N}, ... ]
  
\      /        /        \    |

head<-->O<-->O<-->O<--->O<--->...   <-->tail

  
=========
O(1) get
O(1) put
O(1) eviction
=========
=========
=========
