class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first!=b.first)return a.first>b.first;
            return a.second>b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int x:nums)mpp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>minh;
        for(auto it:mpp){
            int f=it.second;
            int ele=it.first;
            
            pair<int,int>curr={f,ele};
            if(minh.size()<k){
                minh.push(curr);
                continue;
               
            }
            if(curr.first<minh.top().first)continue;
            minh.pop();
            minh.push(curr);
            

           

        }
        vector<int>res;
       while(!minh.empty()){
        res.push_back(minh.top().second);
        minh.pop();
       }
       return res;

        
    }
};