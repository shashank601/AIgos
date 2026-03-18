class Solution {
public:
    (-all = INT_MIN   overflow, postive have one less capacity or abs(INT_MIN) is undefined)
    

      vector<int> singleNumber(vector<int>& nums) {
        long all = 0;
        for (auto num : nums) {
            all ^= num;
        }

        long mask = all & (-all);

        int grpA = 0;
        int grpB = 0;

        for (auto num : nums) {
            
            if (mask & num) {
                grpA ^= num;
            } else {
                grpB ^= num;
            }
        }
        return {grpA, grpB};
    }
};



===

n & (-n)

gives rightmost set bit

xxxx1000

flip: 
xxxx0111

add 1:

xxxx0111   <--- on flip becomes rightmot 1 becomes 0
     + 1
--------
xxxx1000    <--- adding one preserves it back and prefixe becomes eqv.

doing  & only keeps rightmost set bit


===
this rightmost set bits say x ^ y have this bit is different (property h)   <-- dont know which have 1 and which hav 0 but its diff 
we use it make two grps eventually dups will cancel out and we left with actual ans




