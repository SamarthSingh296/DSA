class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int low=0;
        int res=-1;
        int n=fruits.size();
        for(int high=0;high<n;high++){
            mpp[fruits[high]]++;
            while(mpp.size()>2){
                mpp[fruits[low]]--;
                if(mpp[fruits[low]]==0)mpp.erase(fruits[low]);
                low++;
            }
            if(mpp.size()==2||mpp.size()<2){
                int len=high-low+1;
                res=max(len,res);
            }

        }
        return res;

        
    }
};