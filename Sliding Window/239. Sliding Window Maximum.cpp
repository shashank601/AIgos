class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {

            while (!dq.empty() &&  dq.front() < i) {                        <--- remove expired index from front
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[j]) {               <--- remove elements that are smaller than me
                dq.pop_back();
            }

            dq.push_back(j);
            
            if (j - i + 1 == k) {
                ans.push_back(nums[dq.front()]);
                i++;
            }

        }
        return ans;
    }
};


[3, -1, 5]
Can 3 ever become maximum again while 5 exists to its right?

Maintain deque in decreasing order
===========

pq apporach is unoptimal

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            int num = nums[j];
            pq.push({num, j});


            if (j - i + 1 == k) {
                while (!pq.empty() && pq.top().second < i) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
                i++;
            }
        }

        return ans;
    }
};
