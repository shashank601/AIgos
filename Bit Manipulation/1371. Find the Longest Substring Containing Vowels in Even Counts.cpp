class Solution {
public:
    int findTheLongestSubstring(string s) {
        int parity = 0;
        unordered_map<int, int> m;     <--- tracks parity first occurence  (if a parity already  occured the substring is a valid option, odd - odd = even and even - even = even)
        m[0] = -1;                    <-- imp

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') parity ^= (1 << 0);
            else if (s[i] == 'e') parity ^= (1 << 1);
            else if (s[i] == 'i') parity ^= (1 << 2);
            else if (s[i] == 'o') parity ^= (1 << 3);
            else if (s[i] == 'u') parity ^= (1 << 4);

            if (m.count(parity)) {
                ans = max(i - m[parity], ans);   <-- no +1
            } else {
                m[parity] = i;
            }
        }
        return ans;
    }
};










// base case: state 0 at index -1




===
0 ^ 1 = 1
1 ^ 1 = 0
So XOR with 1 flips the bit.
===

Prefix logic always uses:
i - j
No +1.
r - l: [6-2, 7-3, 8-4, 12-8, 14-10] = [4, 4, 4, 4, 4]
Including it in the substring adds the flips at l again → net parity of substring is wrong
====

If two indices have same mask, then:
→ substring between them has all vowels even

eg1.
l: [2, 3, 4, 8, 10]   → parity = [0,1,0,0,0]
r: [6, 7, 8, 12, 14]  → parity = [0,1,0,0,0]
sub:
[6-2, 7-3, 8-4, 12-8, 14-10]
= [4, 4, 4, 4, 4]

eg2.
If parity differs
l: [2, 3, 4, 8, 10]   → [0,1,0,0,0]
r: [5, 7, 8, 12, 14]  → [1,1,0,0,0]
Subtract:
[3, 4, 4, 4, 4]
→ one odd → invalid
====

keep current mask
store first occurrence of each mask
when mask repeats → valid substring

Same parity at two points ⇒ subtraction gives all even ⇒ valid substring
