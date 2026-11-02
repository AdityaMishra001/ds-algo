class Solution {
public:
    void insertionSort(vector<int>&nums,int low,int high){
        int i=low+1;
        while(i<=high){
            int curr=nums[i];
            int j=i-1;
            while(j>=low && nums[j]>curr){
                nums[j+1]=nums[j];
                j--;
            }
            nums[j+1]=curr;
            i++;
        }
    }
    void merge(vector<int>&nums,int low,int mid,int high){
        // if(is_sorted(nums.begin()+low,nums.begin()+high+1))
        //     return;
        // if(is_sorted(nums.rbegin()+high,nums.rbegin()+low+1)){
        //     reverse(nums.rbegin()+high,nums.rbegin()+low+1);
        //     return;
        // }
            
        vector<int>temp;
        int i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=high){
            temp.push_back(nums[j++]);
        }
        for(int k=0;k<temp.size();k++){
            nums[k+low]=temp[k];
        }
    }
    void timSort(vector<int>&nums,int low,int high){
        if(low>=high)return;

        if(high-low+1<=32){
            insertionSort(nums,low,high);
            return;
        }

        // if(is_sorted(nums.begin()+low,nums.begin()+high+1))
        //     return;
        // if(is_sorted(nums.rbegin()+high,nums.rbegin()+low+1)){
        //     reverse(nums.rbegin()+high,nums.rbegin()+low+1);
        //     return;
        // }

        int mid= low+(high-low)/2;
        timSort(nums,low,mid);
        timSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        timSort(nums,0,nums.size()-1);
        return nums;
    }
};