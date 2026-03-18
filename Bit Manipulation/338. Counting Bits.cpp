class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.reserve(n);
        for (int i = 0; i <= n; i++) {
            int num = i;
            int cnt = 0;
            while (num) {
                num = num & (num - 1);
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};




This runs only as many times as there are 1s.
n & (n - 1) removes the lowest set bit.
& 1001
= 1000

Again, lowest 1 removed.


What happens when you subtract 1 from a number in binary?

This is the key.
Take a number in general form:

xxxx1000...000
(some bits, then a 1, then only zeros)

When you subtract 1:
xxxx0111...111
Why?

Because subtraction borrows from the rightmost 1.

ans now we do & ops
  
  tis portion is same so we will get correct prefix
   100]1000   (n)
&  100]0111   (n - 1)
-----------
   1000000
