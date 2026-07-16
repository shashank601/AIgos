class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        
        int cnt = 0;


        vector<int> v(mx + 1, 0);         <-- O(1) presence check

        for (int x : nums) {
            v[x] = 1;
        }

        for (int i = 1; i <= mx; i++) {
            
            int k = 0;
            for (int cand = i; cand <= mx; cand += i) {
                if (v[cand]) {
                    k = gcd(k, cand);
                }
            }

            if (k == i) cnt++;
        }

        return cnt;
    }
};


==========

  so 10^5 means

  2^n explosion will be TLE
-----------

now a better apporach is 
check wether form 

1 to MAX
how many are valid gcd

1?
2?
3?
4?

N?

because of Monotonic behaviour of gcd
-------------

how we achieve this ?

we find all muliptle of i => from[1, max]
-----------

then we check for gcd of all mulitple element of that i

-------------

Suppose the existing multiples of x are:

a1,a2,a3,...,ak
	​
The GCD of all of them is:
G=gcd(a1,a2,...,ak)

Now the important property:

Adding numbers can only decrease or keep GCD

kyuki adding num islike introducing more dividiblily constratins
----------------

so opposite is also true 
ek set ka min gcd us pure set k gcd ke barabar hoga 

yani no subset can procuduce smaller gcd then that (implication of property)

  gcd(all elements)≤gcd(any subset)
-----------------

but if a num muliptle exist in array
it dont mean that num is valid gcd 

eg 12 24 36
if i = 6
then 

even if all are mulitple but actual gcd is 12

so thats why we check for gcd after finding all elements
---------

and we take all elements becasues thats the best case to find mn possible gcd of that grp
---------


Don't memorize:

"Check multiples."

Remember the reasoning:

Subsets are impossible:
2n
For a candidate GCD x, only multiples of x matter.
The GCD of all multiples is the minimum possible GCD.
If that minimum equals x, then x is achievable.
Iterate over values because:
constriant is small
-----------------

  
