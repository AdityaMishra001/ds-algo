class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k,int mid){
        int bouquets=0,consecutive=0,n=bloomDay.size();

        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                consecutive++;
                 if(consecutive==k){
                    bouquets++;
                    consecutive=0;  //reset after each bouquet
                     if(bouquets==m)
                      return true;
                 }
            }else{
                consecutive=0;//non adjacent
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
       

        if(n<(long long)m * k)
        return -1;
        
        int mn=bloomDay[0],mx=bloomDay[0];
        for(int i=1;i<n;i++){
           mn=min(mn,bloomDay[i]);
           mx=max(mx,bloomDay[i]);
        }

        int l=mn,r=mx,mid=-1,ans=mx; //min to max of blooming days

        while(l<=r){
            mid=l+(r-l)/2;

            if(check(bloomDay,m,k,mid)){//if possible then
                //save
                ans=mid;
                //look for better
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

return ans;
    }
};