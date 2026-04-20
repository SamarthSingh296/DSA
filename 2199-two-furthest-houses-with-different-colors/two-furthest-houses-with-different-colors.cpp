class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<r){
            if(colors[l]!=colors[r]){
                ans=max(ans,abs(l-r));
            }
            r--;
           

        }
        l=0,r=n-1;
          while(l<r){
            if(colors[l]!=colors[r]){
                ans=max(ans,abs(l-r));
            }
            l++;
           

        }
        return ans;
        


        
    }
};