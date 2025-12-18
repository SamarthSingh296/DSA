class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>maxh(gifts.begin(),gifts.end());
        long long sum=0;
        while(k>0){
            long long sq=maxh.top();
            maxh.pop();
            maxh.push((long long)floor(sqrt(sq)));
            k--;
    
           
        }
        while(!maxh.empty()){
            sum+=maxh.top();
            maxh.pop();
        }
        return sum;
        
    }
};