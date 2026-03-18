class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
       
        while (left < right) {
            right = right & (right - 1);
        }
        return right;
    }
};

right     = 1101 00  (example)
right - 1 = 1100 11
AND       = 1100 00  <= lowest set bit removed


keeps removing the lowest bit of right until 
right <= left. At that point, 
right holds only 
the common prefix of the original left and right.


  & never increases bit 
