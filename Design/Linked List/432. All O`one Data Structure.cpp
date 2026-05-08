class Node {
public:

    int freq;
    unordered_set<string> st;

    Node *next, * prev;

    Node(int f): freq(f), next(nullptr), prev(nullptr) {}
};

class AllOne {
public:
    Node* head;
    Node* tail;

    unordered_map<string, Node*> buck;

    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void insertNodeAtFront(Node* node) {
        int newFreq = node->freq + 1;
        Node* newNode = new Node(newFreq);

        newNode->next = node->next;
        newNode->next->prev = newNode;

        node->next = newNode;
        newNode->prev = node;
    
    }

    void insertNodeAtBack(Node* node) {
        int newFreq = node->freq - 1;
        Node* newNode = new Node(newFreq);
        
        newNode->prev = node->prev;
        newNode->prev->next = newNode;

        node->prev = newNode;
        newNode->next = node;
    }

    void removeNode(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;

        delete node;
    }

    void promote(string key) {
        Node* node = buck[key];

        node->st.erase(key);

        if (node->next->freq != node->freq + 1) {
            insertNodeAtFront(node);
        }

        Node* old = node;
        node = node->next;

        node->st.insert(key);
        buck[key] = node;

        if (old->st.empty()) {
            removeNode(old);
        }
    }

    void demote(string key) {
        Node* node = buck[key];

        node->st.erase(key);

        if (node->prev == head || node->prev->freq != node->freq - 1) {
            insertNodeAtBack(node);
        }

        Node* old = node;
        node = node->prev;

        node->st.insert(key);
        buck[key] = node;

        if (old->st.empty()) {
            removeNode(old);
        }
    }

    void inc(string key) {
        if (!buck.count(key)) {

            if (head->next->freq != 1) {
                insertNodeAtFront(head);
            }

            Node* node = head->next;

            node->st.insert(key);
            buck[key] = node;
            return;
        }

        promote(key);
    }
    
    void dec(string key) {
        int freq = buck[key]->freq;
        if (freq != 1) {
            demote(key);
            return;
        }

        head->next->st.erase(key);
        buck.erase(key);
        if (head->next->st.empty()) {
            removeNode(head->next);
        }

    }
    
    string getMaxKey() {
        auto& s = tail->prev->st;
        if (!s.empty()) {
            return *(s.begin());
        }
        return "";
    }
    
    string getMinKey() {
        auto& s = head->next->st;
        if (!s.empty()) {
            return *(s.begin());
        }
        return "";
    }
};
============



* Forgot deleting key when freq becomes 0 in `dec`

* Left empty freq=1 node after deletion

* `getMaxKey/getMinKey` copied entire set   <-- now use &

* No empty-structure sentinel check

* Used misleading names (`insertNodeAtFront/Back`)  <-- bteer is insert_after/insert_before

* Unsafe `buck[key]` access in `dec`

* Relied on accidental sentinel behavior   <-- lie

* Did not preserve “no empty frequency node” invariant  


* Missed cleanup after removing last key from bucket

* Weak invariant tracking during edge cases

* Mixed structural operations with semantic naming

* No destructor / memory cleanup  <-- i dont care, judge does teh cleanup anyway


* Initially treated linked list mechanics as primary instead of invariants  <-- ???

* Delayed handling of zero-frequency lifecycle

* Did not think through fully-empty state transitions


