class Solution {
public:
    void printNums(vector<int>&nums){
        cout<<"  ";
        for(const int &num:nums){
            if(num==0){
                cout<<"00 ";
                continue;
            }
            cout<<num<<" ";
        }cout<<endl;
    }
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        //calulating post values
        for(int i=n-2;i>=0;i--){
            int diff=(nums[i+1]-nums[i]);
            int len=(n-1-i);
            ans[i]=ans[i+1]+ diff*len;
        }
        //calculating post values
        int prev=0;
        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            int len=i;
            ans[i]+=prev+ diff*len;
            prev= prev+diff*len;//because ans contians values from ans of post value calculations
        }
        return ans;
    }
};