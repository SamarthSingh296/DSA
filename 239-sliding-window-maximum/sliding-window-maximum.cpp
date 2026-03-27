class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxheap;
        int n=nums.size();
        for(int i=0;i<k;i++)maxheap.push({nums[i],i});
        vector<int>res;
        res.push_back(maxheap.top().first);
        for(int i=k;i<n;i++){
            maxheap.push({nums[i],i});
            while(maxheap.top().second<=i-k)maxheap.pop();
            res.push_back(maxheap.top().first);
        }
        return res;
        
        
    }
};