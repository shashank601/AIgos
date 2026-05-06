class MyHashSet {
public:
    vector<list<int>> st;
    MyHashSet() {
        st.assign(10'000, list<int>());                    <-- assign needs both arg or better is to use resize or reserve 
    }
    
    void add(int key) {
        int hash = key % 10'000;
        list<int>::iterator iter = st[hash].begin();

        for (; iter != st[hash].end(); iter++) {
            if (*iter == key) return;
        }
        st[hash].push_back(key);                    <-- insert() needs iter and value, push_back is fine with ll
    }
    
    void remove(int key) {
        int hash = key % 10'000;
        list<int>::iterator iter = st[hash].begin();

        for (; iter != st[hash].end(); iter++) {
            if (*iter == key) {
                st[hash].erase(iter);
                return;                              <-- or AS error
            }
        }
        
    }
    
    bool contains(int key) {
        int hash = key % 10'000;
        list<int>::iterator iter = st[hash].begin();

        for (; iter != st[hash].end(); iter++) {
            if (*iter == key) {
                return true;;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
