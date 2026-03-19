
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        int dvd = dividend > 0 ? -dividend : dividend;
        int dvs = divisor  > 0 ? -divisor  : divisor;
        int result = 0;

        while (dvd <= dvs) {
            int chunk = dvs, multiple = -1;

            while (chunk > (INT_MIN >> 1) && dvd <= (chunk << 1)) {
                chunk <<= 1;
                multiple <<= 1;
            }

            dvd      -= chunk;
            result += multiple;          
        }

        return ((dividend ^ divisor) >= 0) ? -result : result;
    }
};











====
Hint: “Can I remove MORE than one divisor at a time?”
      “work entirely in negative space”
====

without using multiplication, division, and mod operator.

i can subtract divisor from dividend untill dividend is  >= divisor and then return quotient.
but not scalable though (4.2B % 1) => 4 * 10^9 ops tle

is there any way i can subtract faster?

Instead of:
“Can I subtract 1 again?”
Ask:
“What is the largest multiple of 1 I can subtract in one shot?”


Example
43 ÷ 3
Instead of taking away one 3 at a time, 
we take away groups of 3. We make these groups by doubling the divisor over and over untill we exceed the dividend itslef:
Rules:
 No `/ * %`
 
   [Only subtraction + doubling (shifts)]

Step 1: Build “chunks” of the divisor (DECIMAL, not binary)

Start from the divisor and keep doubling:
3 × 1  = 3
3 × 2  = 6
3 × 4  = 12
3 × 8  = 24
3 × 16 = 48  (too big for 43, stop)
So usable chunks are:
3, 6, 12, 24                      <----------- we take the biggest one, afte that we will again look at this menu with remaining pile

Each chunk corresponds to:
1, 2, 4, 8   (how many 3s)
----------------------------------


  
That "huge pile" 🧱 feels weird because in normal long division,
we usually try to get as close as possible to the target in one go. 
But here, we are restricted to using only **powers of 2** () 
because that’s what a computer can do lightning-fast.
Think of it like paying a 
$40 debt 💵 
using only special "binary checks" that come in specific amounts:

Check A:  (3  x1)
Check B:  (3  x2)
Check C:  (3  x4)
Check D:  (3  x8)
Check E:  (3  x16)  <--- too big

Why 16 is left
When you hand over the $24 check (the largest one you can use for now),

the cashier says, "Okay, you've paid part of it, but you still owe me $16."
That $16 isn't the "final remainder" like you’d see in a math textbook. 
It is just the **remaining debt** you still have to pay off using your other checks.


The 16 is the "new starting amount" 
because it is the only part of the original pile 
you haven't put into boxes yet. 

You are "resetting" the problem to: 
"How many bags of 3 can I get out of these 16 apples?"    (3    6   12   24  => 12)
                                                        (1grp 2grp 4grp 8grp)  



The reason we stick to powers of 2 (2,4,8,16…) 
isn't because they are the "best" at shrinking the pile, 
but because they are the only ones we can calculate lightning-fast without using the multiplication operator (*).
shifting is our ONLY "legal" way to grow our divisor quickly.


eg.
40 ÷ 3
Quotient = 13
Binary: 13 = 8 + 4 + 1

So:
40 = 3×13 + 1
40 = (3×8) + (3×4) + (3×1) + 1
=====
Why this decomposition is the solution

Because once you choose a bit 2^k in q, the equation forces:
dividend -= divisor × 2^k

And divisor × 2^k is legal via shifting.
So the algorithm becomes:

q = 0
while dividend >= divisor:
    find largest k such that (divisor << k) <= dividend
    dividend -= (divisor << k)
    q += (1 << k)

You are discovering the binary digits of q from MSB to LSB.
That’s binary long division.


====
“How can I generate larger multiples of divisor without multiplication?”
  with shifting adding and subtraction
d
2d
4d
8d
16d
====
divisor × (2^k and local h)
So quotient becomes:

q = sum of powers of 2
That is literally:

binary representation of q

2^k → contributes to quotient
divisor × 2^k → reduces dividend



We are NOT asking:
how many divisors fit in dividend?

We are asking:
what is the largest power-of-2 multiple of divisor I can subtract right now?

----

5lakh / 5k
= we know 5k

but let
5L / 5k = x

  x means how many 5k s
1·4096
0·2048
0·1024
1·512
1·256
1·128
0·64
0·32
0·16
1·8
rest 0

so 5k (x) is 4096(chunk1) + 512(chunk2) + 256 + 128 + 8 
  
====
Division is about absolute magnitudes, not signed comparison.

(rules are same as mulplying negatives)
Same signs → positive
Different signs → negative
XOR

(dividend < 0) ^ (divisor < 0)


must reduce the problem too...
|dividend| >= |divisor|


===============

  
  
  
  
so using ll or u is not allowed in problem...

below approach becomes useless but good to know..
  
abs(INT_MIN)   // overflow => UB
You think this is safe:
unsigned int a = abs(dividend);  <---------- abs excute first before assignemnent
Because a is unsigned.
It is not safe.

cant do ((u)dividend) too
abs is defined for signed types:

int abs(int)
long labs(long)
long long llabs(long long)

There is no abs(unsigned int) <------------------------- unsigned dont need abs


Why the “ugly” version is the only correct one (without long long)
unsigned int a = dividend < 0 ? -(unsigned int)dividend : dividend;
  
  ====
off topic:
ceil(a / b) = (a + b - 1) / b
