class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        arr[0] = pref[0];
        
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = pref[i] ^ pref[i - 1];
        }

        return arr;
    }
};




O(1) space
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int prev = pref[0];
        for (int i = 1; i < pref.size(); i++) {
            int temp = pref[i];
            pref[i] = (pref[i] ^ prev);
            prev = temp;
        }

        return pref;
    }
};
