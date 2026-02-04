class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<int>>minh;
        // for(int x:nums){
        //     minh.push(x);
        //     if(minh.size()>k)minh.pop();
        // }
        // return minh.top();
        priority_queue<int>maxh;
        for(int x:nums)maxh.push(x);
        for(int i=1;i<k;i++)maxh.pop();
        return maxh.top();
        
    }
    
};