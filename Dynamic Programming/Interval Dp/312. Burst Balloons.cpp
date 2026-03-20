class Solution {
public:
    int g(vector<int>& nums, int l, int r, auto& dp) {
        if (dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for (int i = l + 1; i < r; i++) {
            int coins = nums[l] * nums[i] * nums[r];
            int score =  g(nums, l, i, dp) + g(nums, i, r, dp);
            ans = max(ans, coins + score);
        }
        return dp[l][r] = ans;
        
        
    }
    int maxCoins(vector<int>& nums) {
        vector<int> newNums;
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size()  + 2, -1));
        newNums.push_back(1);
        for (auto val : nums) newNums.push_back(val);
        newNums.push_back(1);
        return g(newNums, 0, newNums.size() - 1, dp);

    }
};




======
“waiting balloon behaves like a temporary wall for its subproblems”    <-- explaination of disappearance


subproblem
[wall/maybe temp................wall/maybe temp]

there are ballons inside which are deciding who will  get popped last 

names: a b c d e f 

which ever will burst last

becomes temp wall for remaining two intervals

it happens again and again untill

only one ballon in interval left so  => [wall ballon wall]
from here two further recursion call excutes

[wall wall]  and [wall wall]  both returns 0
and after this

our original balloon pops, and unwinding occurs => this interavl popped from stack and returns


first burst will be when there is one choice in interval yniki  [w b w] 

after this burst somenoe waiting outside will clear remainnig interval and then lastly burst itself


[...................................]
for some idx

[...............]  [................]

for some idx       for some idx
[........] [....]  [.........] [.....]




[...] first burst
[..][..]
  0   0



last and then
jo second last hoga uski ek wall temp hogi(last se) 


and 
behaviour:

[Tw b w] <- b bursted

returned to
[w b - w]  


so on so on

and ek time ayega jb
do intervals honge [      X(return idhr  hua hoga middle me somewhere)          ] [                             ] 

====

Why “last” works

If i is last in (l, r):
everything between (l, i) is already gone
everything between (i, r) is already gone
So neighbors of i are fixed:
left = l
right = r


We don’t simulate bursting.

We assume:
    everything except one balloon is already gone,
    then compute its cost.

===
since ballons are not removed or marked 

the disapperace mechanism is, 
using boundary to calc score for bursted ballon
and not neighbor

[w   a b c   w]

c burst it used b and w

b burst it used a and w

a burst it used w and w 

=====


[ 🧱 , 🎈 , 🎈 , 🎈 , 🧱 ]
         4    5    6

pick one 🎈 as LAST
→ everything inside becomes ❌
→ only its two walls remain


-----------------------------------------
case1: 5 is last
[ 🧱 , ❌ , 🎈5 , ❌ , 🧱 ]

So before bursting 5:
left part (🎈4) must be gone
right part (🎈6) must be gone

Left subproblem (only 🎈4)
[ 🧱1 , 🎈4 , 🧱5 ]
💥 4 → 1×4×5
Right subproblem (only 🎈6)
[ 🧱5 , 🎈6 , 🧱1 ]
💥 6 → 5×6×1

Now LAST burst
[ 🧱1 , 🎈5 , 🧱1 ]
💥 5 → 1×5×1

-------------------------------------------

Case 2: 🎈4 is LAST
[ 🧱 , 🎈4 , ❌ , ❌ , 🧱 ]     <---- note since 4 is last it waits for g() and g(w, b1,b2, w)  

-> in this if b2 is last it wait for g(w, b1, w/b2 is wall) and 
-> if b1 is last it waist for        g(w/b1 is wall, b2, w)

So:
right side (5,6) solved first
Solve (5,6)

Two choices inside:
5 last
6 last

Example (6 last):

💥 5 → 4×5×6
💥 6 → 4×6×1

Then LAST (4)
💥 4 → 1×4×1

--------------------------------------
Case 3: 🎈6 is LAST

Same logic:

[ 🧱 , ❌ , ❌ , 🎈6 , 🧱 ]

Left (4,5) solved first, then 6.

Your confusion line
“ball becomes wall”
Fix:

Removed balloons just disappear.







=====
eg.
Input:
[5, 6] → [1, 5, 6, 1]

Only one way:

🧱 5  🎈6  🧱1
💥 6 → 5×6×1 = 30

🧱 1  🎈5  ❌  🧱1
💥 5 → 1×5×1 = 5

====
eg. [4, 5, 6] → [1, 4, 5, 6, 1]
Call: solve(0,4)

Input:
solve(0,4)
├── k = 1  (🎈4 is LAST)
│   ├── solve(0,1) → 0
│   └── solve(1,4)
│       ├── k = 2  (🎈5 is LAST)
│       │   ├── solve(1,2) → 0
│       │   └── solve(2,4)
│       │       ├── k = 3  (🎈6 is LAST)
│       │       │   ├── solve(2,3) → 0
│       │       │   └── solve(3,4) → 0
│       │       │   💥 6 → 🧱5 × 🎈6 × 🧱1 = 30


│       │   💥 5 → 🧱4 × 🎈5 × 🧱1 = 20
│       │   total (subtree) = 30 + 20 = 50
│       │



│       ├── k = 3  (🎈6 is LAST)
│       │   ├── solve(1,3)
│       │   │   ├── k = 2  (🎈5 is LAST)
│       │   │   │   ├── solve(1,2) → 0
│       │   │   │   └── solve(2,3) → 0
│       │   │   │   💥 5 → 🧱4 × 🎈5 × 🧱6 = 120
│       │   └── solve(3,4) → 0
│       │   💥 6 → 🧱4 × 🎈6 × 🧱1 = 24
│       │   total (subtree) = 120 + 24 = 144
│       │
│       => solve(1,4) = max(50, 144) = 144
│
│   💥 4 → 🧱1 × 🎈4 × 🧱1 = 4
│   total = 144 + 4 = 148
│




├── k = 2  (🎈5 is LAST)
│   ├── solve(0,2)
│   │   ├── k = 1  (🎈4 is LAST)
│   │   │   ├── solve(0,1) → 0
│   │   │   └── solve(1,2) → 0
│   │   │   💥 4 → 🧱1 × 🎈4 × 🧱5 = 20
│   │   ⇒ solve(0,2) = 20
│   │
│   └── solve(2,4)
│       ├── k = 3  (🎈6 is LAST)
│       │   ├── solve(2,3) → 0
│       │   └── solve(3,4) → 0
│       │   💥 6 → 🧱5 × 🎈6 × 🧱1 = 30
│       ⇒ solve(2,4) = 30
│
│   💥 5 → 🧱1 × 🎈5 × 🧱1 = 5
│   total = 20 + 30 + 5 = 55
│






└── k = 3  (🎈6 is LAST)
    ├── solve(0,3)
    │   ├── k = 1  (🎈4 is LAST)
    │   │   ├── solve(0,1) → 0
    │   │   └── solve(1,3)
    │   │       ├── k = 2  (🎈5 is LAST)
    │   │       │   ├── solve(1,2) → 0
    │   │       │   └── solve(2,3) → 0
    │   │       │   💥 5 → 🧱4 × 🎈5 × 🧱6 = 120
    │   │   💥 4 → 🧱1 × 🎈4 × 🧱6 = 24
    │   │   total = 120 + 24 = 144
    │   │
    │   ├── k = 2  (🎈5 is LAST)
    │   │   ├── solve(0,2)
    │   │   │   ├── k = 1
    │   │   │   │   💥 4 → 🧱1×🎈4×🧱5 = 20
    │   │   └── solve(2,3) → 0
    │   │   💥 5 → 🧱1 × 🎈5 × 🧱6 = 30
    │   │   total = 20 + 30 = 50
    │   │
    │   ⇒ solve(0,3) = max(144, 50) = 144
    │
    └── solve(3,4) → 0

    💥 6 → 🧱1 × 🎈6 × 🧱1 = 6
    total = 144 + 6 = 150
=====
returning when array have 2 elements left.  => returns 0
cobining step => solve(1,4)


eg

input [4, 5, 6, 9] → padded [1, 4, 5, 6, 9, 1]

solve(0,5)
├── k = 1                                     <-- now 1 burst     [1, [4], 1]
│   ├── solve(0,1)
│   └── solve(1,5)
│       ├── k = 2                            <---- now 2 burst    [1, 4, [5], 1]
│       │   ├── solve(1,2)
│       │   └── solve(2,5)
│       │       ├── k = 3                     <---  now 3 burst   [1, 4, 5, [6], 1]
│       │       │   ├── solve(2,3)        
│       │       │   └── solve(3,5)
│       │       │       ├── k = 4             <---- yani 4 burst  [1, 4, 5, 6, [9],1]   (first burst or assume it bursts LAST iin interval)   => g() + g() + n[l]*n[]*n[r] <-- not i - 1 or i + 1
│       │       │           ├── solve(3,4)    <--- everything IN 3,4 gone                                                                         0     0        6*9*1
│       │       │           └── solve(4,5)    <--- everything IN 4,5 gone
│       │       └── k = 4
│       │           ├── solve(2,4)
│       │           │   ├── k = 3
│       │           │       ├── solve(2,3)
│       │           │       └── solve(3,4)
│       │           └── solve(4,5)
│       ├── k = 3
│       │   ├── solve(1,3)
│       │   │   ├── k = 2
│       │   │       ├── solve(1,2)
│       │   │       └── solve(2,3)
│       │   └── solve(3,5)
│       │       ├── k = 4
│       │           ├── solve(3,4)
│       │           └── solve(4,5)
│       └── k = 4
│           ├── solve(1,4)
│           │   ├── k = 2
│           │   |   ├── solve(1,2)
│           │   |   └── solve(2,4)
│           │   |       ├── k = 3
│           │   |           ├── solve(2,3)
│           │   |           └── solve(3,4)
│           │   ├── k = 3
│           │       ├── solve(1,3)
│           │       │   ├── k = 2
│           │       │       ├── solve(1,2)
│           │       │       └── solve(2,3)
│           │       └── solve(3,4)
│           └── solve(4,5)
│
├── k = 2
│   ├── solve(0,2)
│   │   ├── k = 1
│   │       ├── solve(0,1)
│   │       └── solve(1,2)
│   └── solve(2,5)
│       ├── k = 3
│       │   ├── solve(2,3)
│       │   └── solve(3,5)
│       │       ├── k = 4
│       │           ├── solve(3,4)
│       │           └── solve(4,5)
│       └── k = 4
│           ├── solve(2,4)
│           │   ├── k = 3
│           │       ├── solve(2,3)
│           │       └── solve(3,4)
│           └── solve(4,5)
│
├── k = 3
│   ├── solve(0,3)
│   │   ├── k = 1
│   │   │   ├── solve(0,1)
│   │   │   └── solve(1,3)
│   │   │       ├── k = 2
│   │   │           ├── solve(1,2)
│   │   │           └── solve(2,3)
│   │   ├── k = 2
│   │       ├── solve(0,2)
│   │       │   ├── k = 1
│   │       │       ├── solve(0,1)
│   │       │       └── solve(1,2)
│   │       └── solve(2,3)
│   └── solve(3,5)
│       ├── k = 4
│           ├── solve(3,4)
│           └── solve(4,5)
│
└── k = 4
    ├── solve(0,4)
    │   ├── k = 1
    │   │   ├── solve(0,1)
    │   │   └── solve(1,4)
    │   │       ├── k = 2
    │   │       │   ├── solve(1,2)
    │   │       │   └── solve(2,4)
    │   │       │       ├── k = 3
    │   │       │       │   ├── solve(2,3)
    │   │       │       │   └── solve(3,4)
    │   │       ├── k = 3
    │   │           ├── solve(1,3)
    │   │           │   ├── k = 2
    │   │           │       ├── solve(1,2)
    │   │           │       └── solve(2,3)
    │   │           └── solve(3,4)
    │   ├── k = 2
    │   │   ├── solve(0,2)
    │   │   │   ├── k = 1
    │   │   │       ├── solve(0,1)
    │   │   │       └── solve(1,2)
    │   │   └── solve(2,4)
    │   │       ├── k = 3
    │   │           ├── solve(2,3)
    │   │           └── solve(3,4)
    │   ├── k = 3
    │       ├── solve(0,3)
    │       │   ├── k = 1
    │       │   │   ├── solve(0,1)
    │       │   │   └── solve(1,3)
    │       │   │       ├── k = 2
    │       │   │           ├── solve(1,2)
    │       │   │           └── solve(2,3)
    │       │   ├── k = 2
    │       │       ├── solve(0,2)
    │       │       │   ├── k = 1
    │       │       │       ├── solve(0,1)
    │       │       │       └── solve(1,2)
    │       │       └── solve(2,3)
    │       └── solve(3,4)
    └── solve(4,5)

=====

🧱 6  🎈9  🧱1                  <-- g:size 3.   [g:size 2 + g:size2] basiclay 0 and then 9*6*1
💥 9 → 6×9×1 = 54

🧱 5  🎈6  ❌  🧱1
💥 6 → 5×6×1 = 30

🧱 4  🎈5  ❌ ❌  🧱1
💥 5 → 4×5×1 = 20

🧱 1  🎈4  ❌ ❌ ❌  🧱1
💥 4 → 1×4×1 = 4


other branch:
🧱 5  🎈6  🧱9
💥 6 → 5×6×9 = 270

🧱 4  🎈5  ❌  🧱9
💥 5 → 4×5×9 = 180

🧱 1  🎈4  ❌ ❌  🧱9
💥 4 → 1×4×9 = 36

🧱 1  🎈9  🧱1  (last)
💥 9 → 1×9×1 = 9

=====


A balloon k is NOT removed yet
→ so for subproblems, it acts as a boundary (🧱)
→ but it is NOT actually a wall
