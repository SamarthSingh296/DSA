class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        struct Robot{
            int pos;
            int health;
           char dir;
           int idx;

        };
        vector<Robot>robots;
        for(int i=0;i<n;i++){
            robots.push_back({positions[i],healths[i],directions[i],i});
        }
        sort(robots.begin(),robots.end(),[](auto &a,auto&b){
            return a.pos<b.pos;
        });
        stack<int>st;
        for(int i=0;i<n;i++){
            if(robots[i].dir=='R')st.push(i);
            else{

                while(!st.empty()&&robots[i].health>0){
                    int j=st.top();
                    if(robots[i].health>robots[j].health){
                        robots[i].health--;
                        robots[j].health=0;
                        st.pop();
                    }
                    else if(robots[i].health<robots[j].health){
                        robots[j].health--;
                        robots[i].health=0;
                        break;
                    }
                     else {
                        robots[j].health=0;
                        robots[i].health=0;
                        st.pop();
                        break;
                    }
                    if(robots[i].health==0)break;
                    }
                }
            }
        
        vector<pair<int,int>>temp;
        for(auto &it:robots){
            if(it.health>0){
                temp.push_back({it.idx,it.health});
            }

        }
        sort(temp.begin(),temp.end());
        vector<int>res;
        for(auto it:temp){
            res.push_back(it.second);
        }
        return res;



        
    }
};