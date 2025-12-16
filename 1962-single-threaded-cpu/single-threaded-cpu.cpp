class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
         int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
       
        vector<int>ans;
        sort(tasks.begin(),tasks.end());
        long long timer=tasks[0][0];
        int i=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        while(!minh.empty()||i<n){
        while(i<n&&tasks[i][0]<=timer){
            minh.push({tasks[i][1],tasks[i][2]});
            i++;
        }
        if(minh.empty()){
            timer=tasks[i][0];
        }
        else{
            ans.push_back(minh.top().second);
            timer+=minh.top().first;
            minh.pop();
        }
        }
        return ans;
        
    }
};