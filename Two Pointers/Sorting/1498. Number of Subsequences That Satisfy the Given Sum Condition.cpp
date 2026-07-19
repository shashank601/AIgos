class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

      
        vector<int> p(n);
        p[0] = 1;

        for (int i = 1; i < n; i++)
            p[i] = (2LL * p[i - 1]) % 1000000007;


        int l = 0;
        int r = n - 1;

        int ans = 0;
      
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                // capture
                ans = (ans + p[r - l]) % 1000000007;    
                l++;
            } else {
                r--;
            }
        }
        return ans;

    }
};


============

the key is bijection


for every 
subseq there is one to one mapping to sorted subseq 


if [2, 4, 6, 5]  then => [2, 4, 5, 6]

if [5, 4, 2]  then => [2, 4, 5]

if [8, 9, 0, 1]  then => [1, 0, 8, 9]

  .
  .
  .
  .
 2^n and 2^n

=================

since max and min are not monotonic we can sort


also the distance between min and max not matter

[200, 1, 9, 10, 11, 12], target = 200

  
we dont need original order

if 

then sorted version have 
 X, Y, Z

original must have X', Y', Z'
  
same size, same element just order is changed.


[200, 1] => [1, 200]
  
=================


now make left element a must have element and then find right r 

then do math

then move left 

  
