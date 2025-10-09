class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int  n=seen.size();
        if(nums.size()>n)return true;
        else return false;
    }
};