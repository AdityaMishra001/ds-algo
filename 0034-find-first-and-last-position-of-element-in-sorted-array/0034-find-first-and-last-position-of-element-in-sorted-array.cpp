class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
        int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        if(lb==arr.size()||arr[lb]!=x){
            return {-1,-1};
        }
        int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin()-1;
        return{lb,ub};
    }
};