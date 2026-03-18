additional tags: 
hashmap, pref sum


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> pref(arr.size());
        pref[0] = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            pref[i] = arr[i] ^ pref[i - 1];
        }

        unordered_map<int, vector<int>> m;
        m[0].push_back(-1);

        int cnt  = 0;
        for (int i = 0; i < pref.size(); i++) {
            int curr = pref[i];
            if (m.count(pref[i])) {

                for (auto idx : m[pref[i]]) {
                    cnt += (i - idx - 1);    <--- or -(idx + 1)                       valid j in our valid range
                }

            }

            m[pref[i]].push_back(i);
        }

        return cnt;

    }
};

why -1 ? bcz idx is prefsum idx 
so 
left: idx + 1 and 
rigth: i 
and valid j`s : [i - (idx + 1) + 1] - 1  see ques inequalities(< , <=).




a ^ x = 0;
if a^x where
a = a1 ^ a2 and
x = x1 ^ x2 
then 
=> a1^a2^x1^x2 == 0
so
a1 ^a2 ^x1 == x2 
a1 == a2 ^ x1 ^x2 
