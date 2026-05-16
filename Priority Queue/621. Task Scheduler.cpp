class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        

        

        unordered_map<char,int> m;
        for (int i = 0; i < tasks.size(); i++) {
            m[tasks[i]]++;
        }

        priority_queue<int> pq;        <-- didnt asked to build the answer so just int, (we dont care about char used we only care about cooldown separation window 1(my slot) + n(cooldown slot))
        for (auto& [k, v] : m) {
            pq.push(v);
        }

        

        int ans = 0;
        
        while (!pq.empty()) {
            vector<int> temp;


            int time = n + 1;
            while (!pq.empty() && time > 0) {

                if (pq.top() > 1) {
                    temp.push_back(pq.top() - 1);
                }

                pq.pop();
                time--;
                ans++;
            }

            //cout << ans << endl;

            for (auto v : temp) {
                pq.push(v);
            }
          
            if (!pq.empty() && time > 0) {      <-- a check if work still exist only then after add idle time 
                ans += time;
            } 
        }


        return ans;
    }
};
