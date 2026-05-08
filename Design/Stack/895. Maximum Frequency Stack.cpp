class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int, stack<int>> hist;

    int maxFreq;
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int newFreq = ++freq[val];
        maxFreq = max(newFreq, maxFreq);
        hist[newFreq].push(val);
    }
    
    int pop() {
        int val = hist[maxFreq].top();
        hist[maxFreq].pop();

        
        if (hist[maxFreq].empty()) {
            hist.erase(maxFreq);
            maxFreq--;
        }
        freq[val]--;

        return val;
    }
};

===============

we dont delete old entries just push new entries in newFreq

and maintain a maxFreq

================
failed:

this apporach does not preserve history of arrival

class Node {
public:
    int freq;

    list<int> lst;

    Node *next, *prev;

    Node(int f) : freq(f), next(nullptr), prev(nullptr) {}
};



class FreqStack {
public:
    unordered_map<int, Node*> buck; 
    unordered_map<int, list<int>::iterator> lookup; 
   
   
    Node *head, *tail;
    FreqStack() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }
    
    void insertAfter(Node* node) {
        int newFreq = node->freq + 1;
        Node* newNode = new Node(newFreq);

        newNode->next = node->next;
        node->next->prev = newNode;

        newNode->prev = node;
        node->next = newNode;

    }

    void insertBefore(Node* node) {
        int newFreq = node->freq - 1;
        Node* newNode = new Node(newFreq);

        newNode->prev = node->prev;
        node->prev->next = newNode;

        newNode->next = node;
        node->prev = newNode;
    }

    void remove(Node* node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
    }
    
    void push(int val) {
        if (!buck.count(val)) {
            if (head->next->freq != 1) {
                insertAfter(head);
            }

            Node* node = head->next;
            node->lst.push_back(val);

            lookup[val] = --node->lst.end();
            buck[val] = node;
            return;
        }

        Node* node = buck[val];
        node->lst.remove(val);

        if (node->next->freq != node->freq + 1) {
            insertAfter(node);
        }
        Node* old = node;
        node = node->next;

        node->lst.push_back(val);
        buck[val] = node;
        lookup[val] = --node->lst.end();

        if (old->lst.empty()) {
            remove(old);
        }

    }
    
    int pop() {
        auto it = --tail->prev->lst.end();
        int val = *it;
        tail->prev->lst.remove(val);
        if (tail->prev->freq == 1) {
            buck.erase(val);
            lookup.erase(val);
        }

        else {
            Node* node = tail->prev;
            if (node->freq != node->prev->freq + 1) {
                insertBefore(node);
            }

            node = node->prev;

            node->lst.push_back(val);

            lookup[val] = --node->lst.end();
            buck[val] = node;
        }

        if (tail->prev->lst.empty()) {
            remove(tail->prev);
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

==========

a ds that give O 1  erase
and follows fifo ?

list<int> q;
unordered_map<int, list<int>::iterator> mp;
