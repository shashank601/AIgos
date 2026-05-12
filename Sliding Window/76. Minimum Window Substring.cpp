class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_freq;
        

        for (auto& ch : t) {
            t_freq[ch]++;
        }

        int cnt_required = t.length();

        int min_len = INT_MAX;
      
        int start_idx = 0;
        int ans_start = INT_MAX;


        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            
            if (t_freq[ch] > 0) {
                cnt_required--;
            }
            t_freq[ch]--;

            
           
            while (cnt_required == 0) {
                int win_len = start_idx - i + 1;
                
                if (win_len < min_len) {
                    ans_start = start_idx;
                    min_len = win_len; 
                }

                char ch  = s[start_idx];
                
                t_freq[ch]++; 
                if (t_freq[ch] > 0) {
                    cnt_required++;
                }

                start_idx++;
            }

        }

        return min_len == INT_MAX ? "" : s.substr(ans_start, min_len);
    }
};


=========

when we shrink 
and the curr t`s char in s window was not in excess, its freq inc
a +ive freq means (do cnt++) we lost a valid char

and we stop shrinking immediately when cnt != 0
==========



