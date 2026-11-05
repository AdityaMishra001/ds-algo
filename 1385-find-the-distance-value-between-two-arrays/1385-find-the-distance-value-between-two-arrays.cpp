class Solution {
    static const int size= (2*(1e3))+1;
    static const int low= 1e3;
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ct=0;
        bool seen[size]={0};
        for(int &x:arr2){
            seen[x+low]=true;
        }

        for(int &x:arr1){
            int tar1=x+d;
            int tar2=x-d;
            if(tar1<tar2)
                swap(tar1,tar2);
            bool foundException=false;
            for(int t=max(int(-1e3),tar2);t<=min(int(1e3),tar1);t++){
                if(seen[t+low]){
                    foundException=true;
                    break;
                }
            }
            if(!foundException)ct++;
        }
        return ct;
    }
};