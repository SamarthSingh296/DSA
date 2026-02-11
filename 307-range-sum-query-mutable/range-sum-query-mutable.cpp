class NumArray {
    private:
    vector<int>segmentTree;
    int n;
    void  build(int i,int low,int high,vector<int>&nums){
        if(low==high){
            segmentTree[i]=nums[low];
            return;
        }
        int mid=(low+high)>>1;
        build(2*i+1,low,mid,nums);
        build(2*i+2,mid+1,high,nums);
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];

    }
    void update(int i,int idx,int value,int low,int high){
        if(low==high){
            segmentTree[i]=value;
            return;
        }
        int mid=(low+high)>>1;
        if(idx<=mid)update(2*i+1,idx,value,low,mid);
        else update(2*i+2,idx,value,mid+1,high);
        segmentTree[i]=segmentTree[2*i+1]+segmentTree[2*i+2];
    }
    int query(int i,int low,int high,int left,int right){
        if(low>right||high<left){
            return 0;

        }
        int mid=(low+high)>>1;

        if(low>=left&&high<=right)return segmentTree[i];
        return query(2*i+1,low,mid,left,right)+query(2*i+2,mid+1,high,left,right);
    }



public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        segmentTree.resize(4*n);
        build(0,0,n-1,nums);


        
    }
    
    void update(int index, int val) {
        update(0,index,val,0,n-1);

        
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);

        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */