class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total=0;
        int n=neededTime.size();
        int l=0,r=1;
        while(r<=n){
             if(colors[l]==colors[r]){
                if(neededTime[l]<neededTime[r]){
                    total+=neededTime[l];
                    l=r;
                }
                else{
                    total+=neededTime[r];




                }


            }
            else{
                l=r;
            }
            r++;
          
        }
        return total;
        
    }
};