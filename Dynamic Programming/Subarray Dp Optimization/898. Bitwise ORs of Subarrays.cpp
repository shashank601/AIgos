class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev, curr;
        unordered_set<int> ans;


        for (auto& val : arr) {
            curr.clear();   
            curr.insert(val);

            // for (auto& i : prev) {
            //     cout << i << endl;
            // }

            // cout << prev.size() << endl;
            // cout << curr.size() << endl;
           
            ans.insert(val);

            for (auto& old_val : prev) {
                int new_val = old_val | val;
                // cout << new_val << endl;
                ans.insert(new_val);
                curr.insert(new_val);
                
            }
            // cout << "========" << endl;
            prev = curr;
        } 

        return ans.size();
    }
};
