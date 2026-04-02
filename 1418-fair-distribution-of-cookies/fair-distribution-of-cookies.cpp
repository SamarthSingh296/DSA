class Solution {
public:
    int res=INT_MAX;
    int n;
    void explore(vector<int>& cookies,int i,int k,vector<int>&children){
        if(i==cookies.size()){
            int  curr_max=*max_element(children.begin(),children.end());
            res=min(res,curr_max);
            return;
        }

        int cookie=cookies[i];

        for(int start=0;start<k;start++){
            children[start]+=cookie;
            explore(cookies,i+1,k,children);
            children[start]-=cookie;
            


        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int>children(k,0);
        explore(cookies,0,k,children);
        return res;



        
    }
};