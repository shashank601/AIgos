class Solution {
public:
    void g(vector<int>& nums, int idx, auto& curr, auto& ans) {
        if (curr.size() > 1) ans.push_back(curr);
        // if (idx == nums.size()) {
        //     return;
        // }
        unordered_set<int> seen;
        for (int i = idx; i < nums.size(); i++) {
            if (!seen.count(nums[i]) && (
                curr.empty() || curr.back() <= nums[i]
            )) {
                curr.push_back(nums[i]);
                seen.insert(nums[i]);
                g(nums, i + 1, curr, ans); 
                curr.pop_back();
            }
        }

        //g(nums, idx + 1, curr, ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        g(nums, 0, curr, ans);
        return ans;
    }
};



===
Why duplicates happen
Example:
nums = [4, 6, 7, 7]
At some level:
you pick first 7
you pick second 7
Both produce same subsequence paths → duplicates

5. Key observation
Duplicates only happen at the same recursion depth
Not across depths.

Meaning:
at index i, you should not pick the same value twice   <---- kyuki At depth k, we choosing one element from remaining indices. nums = [7, 7]
two choices try to fill the SAME position with SAME value                                                                               i   j
That only occurs at the same recursion depth.


6. So how do we stop that?
At each recursion level:
keep a small used set

if value already used at this level → skip
====

In loop-based backtracking:
for (int i = idx; i < nums.size(); i++)
You already handle:
“take current element”
“skip current element” → happens automatically by moving i  <--- just by moving 
===

Core rule you missed
Two patterns:

Leaf-based (binary recursion)
collect answer at idx == n

Prefix-based (loop backtracking)
collect answer during traversal

You mixed them earlier. Now you partially fixed it.

7. Minimal takeaway

loop → collect early
no loop → collect at leaf

====
Binary thinking: “I will decide everything, then check validity”
Loop thinking: “I will only build valid things, so every step is usable”

===
for recursion
Binary + set →  set<vector<int>> (simple but expensive)
Binary + sorting + skip →  (if(i > idx && nums[i]==nums[i-1])) (only works when order doesn’t matter)

for loop
Loop + local set (optimal) → at each recursion level use unordered_set to avoid picking same value twice

====
From a node, you choose next element, not “decide for index”.

Binary node:
“decision is incomplete”

Loop node:
“this is already a finished valid sequence, but expandable”
