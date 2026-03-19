class Solution {
public:
    int minFlips(int a, int b, int c) {
        // int ab = a | b;
        int flips = 0;

        for (int i = 0; i < 32; i++) {
            int abit = (a >> i) & 1; 
            int bbit = (b >> i) & 1; 
            int cbit = (c >> i) & 1;

            if ((abit || bbit) != cbit) {
                /*
                1 1  0

                0 0  1
                1 0  0
                0 1  0
                */

                if (!(abit && bbit)) flips++;
                else flips += 2;


            }
        }
        return flips;
    }
};
