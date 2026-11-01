class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>leaders=arr;
        int largestSoFar=-1,n=arr.size();
        for(int i=n-1;i>=0;i--){
            leaders[i]=largestSoFar;
            largestSoFar=max(largestSoFar,arr[i]);    
        }
        return leaders;
    }
};