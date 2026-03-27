class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        //reverse each row as it is  given with the formula 

        //find the index like n-k and then reverse a[0,n-k] and a[n-k,n] and then reverse themwhole 
        //this wi;ll give me the array after rotation 
        int m=mat.size();
        int n=mat[0].size();
        k=k%n;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(i%2==0){
                if(mat[i][j]!=mat[i][(j+k)%n])return false;

            }
            if(i%2!=0){
                if(mat[i][j]!=mat[i][(j-k+n)%n])return false;
            }
            }
            
        }
        return true;
        
    }
};
