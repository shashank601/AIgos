class Solution {
public:
    

    int subarrayGCD(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int,int> prev, curr;

        for (auto& val : nums) {

            curr.clear();
            curr[val]++;
            if (val == k) res++;

            for (auto& [old_val, freq] : prev) {
                int new_val = gcd(old_val, val);

                if (new_val == k) res += freq;

                curr[new_val] += freq;
            }
            prev = curr;
        }

        return res;
    }
};


==========
Everything reduces to prime factorization.

Take any number:
n = p₁^e₁ × p₂^e₂ × ...

So each number is just a vector of exponents.

==========

For each prime:

gcd(a, b) = take minimum exponent

Example:

a = 2³ × 3¹
b = 2¹ × 3²

gcd = 2¹ × 3¹ → min(3,1), min(1,2)

===========

Step 4: Extend to 3 numbers
gcd(a, b, c) means:

For each prime:
min(e₁, e₂, e₃)

Now grouping:
gcd(gcd(a, b), c)
= min(min(e₁, e₂), e₃)

But:
min(min(e₁, e₂), e₃) = min(e₁, e₂, e₃)
Same as:

gcd(a, gcd(b, c))
==========

What is the biggest number that divides both exactly?
