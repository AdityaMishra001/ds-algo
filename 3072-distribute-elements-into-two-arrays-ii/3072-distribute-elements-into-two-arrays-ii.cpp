#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<int, null_type, greater_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    int greaterCount(vector<int>& arr,int num){
        int ct=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>num)
                ct++;
        }
        return ct;
    }
    vector<int> resultArray(vector<int>& nums) {
        

        vector<int>arr1(1,nums[0]),arr2(1,nums[1]);
        oset set1,set2; set1.insert(nums[0]),set2.insert(nums[1]);


        for(int i=2;i<nums.size();i++){
            int ct1=set1.order_of_key(nums[i]);
            int ct2=set2.order_of_key(nums[i]);

            if( ct1>ct2){
                arr1.insert(arr1.end(),nums[i]);
                set1.insert(nums[i]);

            }else if(ct1<ct2){
                arr2.insert(arr2.end(),nums[i]);
                set2.insert(nums[i]);
            }else{
                if(arr2.size()<arr1.size()){
                    arr2.insert(arr2.end(),nums[i]);
                    set2.insert(nums[i]);
                }else {
                    arr1.insert(arr1.end(),nums[i]);
                    set1.insert(nums[i]);
                }
            }
        }
        
        
        arr1.insert(arr1.end(),arr2.begin(),arr2.end());
        return arr1;
    }
};
