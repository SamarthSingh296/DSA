class Solution {
public:
    bool areanagrams(const string &a,const string &b){
     if(a.size()!=b.size())return false;
        string x=a,y=b;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(x==y)return true;
        else return false;
        
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>res;
        if(words.empty())return res;
        res.push_back(words[0]);
        for(int i=1;i<words.size();i++){
            if(!areanagrams(words[i],res.back())){
                res.push_back(words[i]);
            }
        }
        return res;

    }
};