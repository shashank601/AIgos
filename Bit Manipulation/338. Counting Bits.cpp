O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1);
        
        for (int i = 0; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};


Binary numbers are not separate objects.
Each number:

=>either comes from i >> 1 (shift structure)
=>or reduces to i & (i - 1) (bit removal)

two dp formulas

===
Binary numbers are not independent → they are derived from smaller numbers.

0 → 0
1 → 1
2 → 10
3 → 11
4 → [10][0]   <-- dp[10] + (i & 1 yaniki last digit, 0 ya 1)
5 → [10][1]
6 → [11]0
7 → [11]1

So:
bits(6) = bits(4) + 1
bits(4) = bits(0) + 1


===
O(nlogn)
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
