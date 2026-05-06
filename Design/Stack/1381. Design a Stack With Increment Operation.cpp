class CustomStack {
public:
    

    vector<int> st;
    vector<int> lzy;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;     <-- "this" is a ptr not obj so no this.x
    }
    
    void push(int x) {
        if (st.size() < maxSize) {
            st.push_back(x);
            lzy.push_back(0);                  <-- must grow together if lzy kept at size 0 inc will res in UB
        }
    }
    
    int pop() {
        if (!st.empty()) {
            int idx = st.size() - 1;
            int res = st[idx] + lzy[idx];
            if (idx - 1 >= 0) lzy[idx - 1] += lzy[idx];
            
            st.pop_back(); lzy.pop_back();

            return res;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        
        if (st.empty()) return;                  <-- testcase (calling inc on empty st)
        
        if (k >= st.size()) {
            lzy[st.size() - 1] += val;
        } else {
            lzy[k - 1] += val;
        }
    }
};


=============

key is effective idx

if asked to inc botton 1k elements by 3
but st.size() is just 10
then just take st.size() - 1  

min(asked, st.size() - 1)  <-- effective idx

not just lzy[1k] += val  <-- wrong

=============

lzy should grow together with main stack

just like we did in minStack problem
in dups case we still pushed min value
