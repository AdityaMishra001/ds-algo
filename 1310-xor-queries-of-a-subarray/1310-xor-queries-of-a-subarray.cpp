class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        if(n==0){
            return {};
        }
        vector<int>prefixXor(n);
        prefixXor[0]=arr[0];

        for(int i=1;i<n;i++){
            prefixXor[i]=prefixXor[i-1]^arr[i];
        }

        vector<int>Xors(queries.size());
        int k=0;
        for(auto it:queries){
            Xors[k]=prefixXor[it[1]];

            if(it[0]!=0)
            Xors[k]^=prefixXor[it[0]-1];
            
            k++;
        }

        return Xors;
    }
};