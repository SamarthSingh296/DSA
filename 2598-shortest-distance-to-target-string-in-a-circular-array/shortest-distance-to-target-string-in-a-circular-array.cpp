class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans=INT_MAX;
        int n=words.size();
        // for(int i=0;i<words.size();i++){
        //     if(words[i]==target){
        //         ans=min({ans,abs(i-startIndex),(n-abs(startIndex-i))});
              
        //     }
        // }
        for(int d=0;d<n;d++){
            int left=(startIndex+d)%n;
            int right=(startIndex-d+n)%n;
            if(words[left]==target)return d;
            if(words[right]==target)return d;
        }
        return -1;
        
    }
};