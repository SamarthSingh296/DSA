class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       int rows=strs.size();
       int cols=strs[0].size();
       int del=0;
       vector<bool>alreadysorted(rows,false);

       for(int col=0;col<cols;col++){
        bool deleted=false;
        for(int row=0;row<rows-1;row++){
            if(!alreadysorted[row]&&strs[row][col]>strs[row+1][col]){
                del++;
                deleted=true;
                break;
            }

        }
        if(deleted)continue;
        for(int i=0;i<rows-1;i++){
            alreadysorted[i]=alreadysorted[i]|strs[i][col]<strs[i+1][col];
        }
       }
            return del;
        
    }
};