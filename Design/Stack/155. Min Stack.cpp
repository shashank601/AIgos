class MinStack {
public:
    stack<int> main;   <-- bad naming  main is works but its also entry point name
    stack<int> support;                     <-- call it minSt (better)

    void push(int val) {
        main.push(val);
        if (support.empty() || val <= support.top()) {
            support.push(val);
        }        
    }


    
    void pop() {
        if (!main.empty()) {
            if (support.top() == main.top()) {
                support.pop();
            }
            main.pop();
        }
    }
    
    int top() {                     <-- no empty check guard
        return main.top();
        
    }
    
    int getMin() {                            
        if (!main.empty()) {
            return support.top();
        }
        return -1;
    }
};

