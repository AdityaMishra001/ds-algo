class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),chunks=0;
        vector<bool>mark(n);
        for(int i=0;i<n;i++){
            if(arr[i]==i)
                continue;

            int left=min(i,arr[i]);
            int right=max(i,arr[i]);
            while(arr[i]!=i){
                swap(arr[i],arr[arr[i]]);
                left=min(left,arr[i]);
                right=max(right,arr[i]);
            }
            bool not_already_mark=true;
            for(int j=left;j<=right;j++){
                if(mark[j])not_already_mark=false;
                else mark[j]=true;
            }
            if(not_already_mark)
            chunks++;
        }
        for(auto it:mark)chunks+=(int(it)==0);
        return chunks;
    }
};