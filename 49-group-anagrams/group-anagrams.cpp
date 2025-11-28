class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>res;
        sort(strs.begin(),strs.end());
        for(string s:strs){
            string key=s;
            sort(key.begin(),key.end());
            mpp[key].push_back(s);
        }
        for(auto it:mpp){
            res.push_back(it.second);
        }
        return res;
        
    }
};