class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cand1,cand2;
        int ct1=0,ct2=0;
        for(int &num:nums){
            if(num==cand1){
                ct1++;
            }else if(num==cand2){
                ct2++;
            }else if(ct1==0){
                cand1=num,ct1=1;
            }else if(ct2==0){
                cand2=num,ct2=1;
            }else{
                ct1--,ct2--;
            }
        }
        ct1=ct2=0;
        for(int &num:nums){
            if(num==cand1)ct1++;
            else if(num==cand2)ct2++;
        }
        vector<int>ans;
        if(ct1>n/3)ans.push_back(cand1);
        if(ct2>n/3)ans.push_back(cand2);
        return ans;
    }
};