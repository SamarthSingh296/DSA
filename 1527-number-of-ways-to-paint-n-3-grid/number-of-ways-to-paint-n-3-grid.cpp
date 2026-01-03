class Solution {
public:
 const int MOD = 1e9 + 7;
    vector<vector<int>> memo;
    
    vector<string> rowStates={"rgr","rgb","rbg","rbr",
                              "grg","grb","gbg","gbr",
                              "bgr","bgb","brb","brg"};
    int solve(int prevStateIdx, int remainRows){
        if(remainRows==0){
            return 1;
        }
        if (memo[prevStateIdx][remainRows]!=-1){
            return memo[prevStateIdx][remainRows];
        }
        int totalWays=0;
        string prevState=rowStates[prevStateIdx];

        for(int i=0;i<12;i++){
            if(i==prevStateIdx)
                continue;
            string curr=rowStates[i];
            bool valid=true;

            for(int j=0;j<3;j++){
                if(prevState[j]==curr[j]){
                    valid=false;
                    break;
                }
            }
            if(valid){
                totalWays = (totalWays+ solve(i, remainRows - 1)) % MOD;
                
            }
        }
        memo[prevStateIdx][remainRows]=totalWays;
        return totalWays;
    }
    
    int numOfWays(int n) {
       int total=0;
       memo.assign(12, vector<int>(n + 1, -1));
       for(int i=0;i<12;i++){
            total= (total+(solve(i,n-1))) % MOD;  
       }
       return total;
    }
    
};