https://leetcode.com/problems/design-hashmap/description/

alpha = num of elements / no of (buck or cells)
=> typical threshold 0.75

alpha is a threshold we check for whther there is a need for resizing(doubling size) array to avoid collisions

=>buck_cnt is choosen randomly

class MyHashMap {
public:
    vector<list<pair<int,int>>> m;
    int buck_cnt = 10'000;

    MyHashMap() {
        m.resize(buck_cnt);
    }
    // void rehash() {
           // use a temp array and double the size and reassign to main array and update buck_cnt
    // }


    int hash(int val) {
        return val % buck_cnt;
    }
    
    void put(int key, int value) {
        // if (m.size() / buck_cnt > 0.75) {
        //     rehash();
        // }

        int idx = hash(key);
        list<pair<int,int>>::iterator iter = m[idx].begin(); 
        for (; iter != m[idx].end(); iter++) {
            if (iter->first == key) {
                iter->second = value;
                return;
            }
        }

        m[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);
        list<pair<int,int>>::iterator iter = m[idx].begin(); 
        for (; iter != m[idx].end(); iter++) {
            if (iter->first == key) {
                return iter->second;
            }
        }
        return -1;
    }

    
    void remove(int key) {
        int idx = hash(key);
        auto iter = m[idx].begin(); 

        for (;iter != m[idx].end(); iter++) {
            if (iter->first == key) {
                m[idx].erase(iter);
                return;
            }
        } 
        return;
    }
};




query:
i always forget why hashing keys  again by changing  modulo by +1
always changes the whole allocated key relation with indexes. 
i want to know some simple reasoing that sticks forever
res:
Think of numbers on a number line

For % 5

0 1 2 3 4 | 5 6 7 8 9 | 10 11 12 13 14
^ ^ ^ ^ ^
remainder pattern repeats every 5

For % 6

0 1 2 3 4 5 | 6 7 8 9 10 11 | 12 13 14
^ ^ ^ ^ ^ ^
pattern repeats every 6

The grouping of numbers changes completely.



Modulo = wrapping numbers around a circle of size m
Change the circle size →
every wrap position changes
Therefore:
Changing m almost always reassigns every key.


  
next sunday
re implement w/o looking for list syntax

=>each buck have lst of pair 
  -> .begin() for iterator cant use *
  -> erase(iter) invalidates the iter so quickly return dont do iter++ 
  -> use -> and not . operator kyuki ptr h n
  -> push_back({}) works with list structure too
