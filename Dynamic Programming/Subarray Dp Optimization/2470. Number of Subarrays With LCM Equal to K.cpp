class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int res = 0;
        using ll = long long;
        unordered_map<ll,ll> prev, curr;

        for (auto& val : nums) {
            curr.clear();
            curr[val]++;
            if (val == k) res++;
            
            for (auto& [old_val, freq] : prev) {
                // int new_val = lcm(old_val, val);
                ll new_val = ((ll)old_val * val)/gcd(old_val, val);
                if (new_val > k) continue;                           <-- key optimization: skip once value exceeds k mark lcm  never decreases
                if (new_val == k) res += freq;
                curr[new_val] += freq;
            }
            for (auto& [k, v] : prev) cout << k << " : " << v << endl;
            cout << "-----" <<endl;
            for (auto& [k, v] : curr) cout << k << " : " << v << endl;
            cout << "=========" << endl;


            prev = curr;
        }
        return res;
    }
};


=======

gcd is monotonically dec : gcd(a, b) ≤ min(a, b)   <--- min 
lcm is monotonically inc : lcm(a, b) ≥ max(a, b)   <--- max
