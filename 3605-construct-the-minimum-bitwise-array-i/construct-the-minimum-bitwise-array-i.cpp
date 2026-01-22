class Solution {
public:

    vector<int> minBitwiseArray(vector<int>& nums) {

        vector<int>result;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==2){
                result.push_back(-1);
                continue;}
            bool found=false;
            for(int j=0;j<32;j++){
                if((nums[i]&(1<<j))!=0)continue;
                //make  it 0;
                else {
                    int x=nums[i]^(1<<(j-1));
                    result.push_back(x);
                    found=true;
                    break;



            }
        }
        }
        return result;






        // vector<int>result;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     bool found=false;
        //     for(int j=0;j<nums[i];j++){
        //         if((j|(j+1))==nums[i]){
        //             result.push_back(j);
        //             found=true;
        //             break;

        //         }
        //     }
        //     if(!found)result.push_back(-1);
        // }
        // return result;
        
    }
};