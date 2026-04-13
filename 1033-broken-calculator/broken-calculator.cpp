class Solution {
public:
    int ans=INT_MAX;
    int recur(int target,int startValue,int op){
        int res;
        if(target==startValue)return op;
        if(target<=startValue)return op+startValue-target;
        if(target%2==0)
        res=recur(target/2,startValue,op+1);
        if(target%2!=0)
        res =recur(target+1,startValue,op+1);
        return res;
        

    }
    int brokenCalc(int startValue, int target) {
        int op=0;
        return recur(target,startValue,op);


        
    }
};