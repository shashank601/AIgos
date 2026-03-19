n / 2  ⇔  n >> 1

unoptimal approach bcz its tail rec so we can easily convert it to iterative version 

class Solution {
public:
    int g(string s) {
        if (s == "1") return 0;
        if (s[s.length() - 1] == '0' && !s.empty()) {
            s.pop_back();
        } else {
            int carry = 1;
            for (int i = s.length() - 1; i >= 0; --i) {
                int bit = s[i] - '0';
                if (bit && carry) {
                    s[i] = '0';
                } else if (carry) {
                    s[i] = '1';
                    carry = 0;
                }

            }
            if (carry) s = '1' + s;
        }
        return 1 + g(s);
    }
    int numSteps(string s) {
        return g(s);
    }
};
===

class Solution {
public:
        
    int numSteps(string s) {
        int ops = 0;

        while (s != "1") {

            if (s[s.length() - 1] == '0' && !s.empty()) {
                s.pop_back();
            } else {
                int carry = 1;
                for (int i = s.length() - 1; i >= 0; --i) {
                    int bit = s[i] - '0';
                    if (bit && carry) {
                        s[i] = '0';
                    } else if (carry) {
                        s[i] = '1';
                        carry = 0;
                    }

                }
                if (carry) s = '1' + s;
            }
            ops++;
        }
        return ops;
    }
};


===

wow
void addOne(string &s) {
    int carry = 1;
    for (int i = s.size() - 1; i >= 0 && carry; --i) {    <--- && carry if carry is 0 so remaining bits are untouched
        if (s[i] == '1') 
          s[i] = '0';
        else { 
          s[i] = '1';
          carry = 0;
        }
    }
    if (carry) s = '1' + s; // overflow
}
