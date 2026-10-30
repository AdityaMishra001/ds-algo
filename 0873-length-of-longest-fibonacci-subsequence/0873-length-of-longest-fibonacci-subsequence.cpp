class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxLen = 0;

        unordered_set<int> seen;
        for (int a : arr)
            seen.insert(a);

        for (int i = 0; i < n - 2; i++) {
            if(i+maxLen-1>=n)
                break;

            for (int j = i + 1; j < n - 1; j++) {
                if(j+maxLen-2>=n)
                    break;

                int currLen = 2;
                int prev2=arr[i],prev1=arr[j];
                long long target = prev2 + prev1;
                //cout<<arr[i]<<"->"<<arr[j];
                if (target > arr[n - 1]){
                    cout<<endl;
                    break;
                }

                while (seen.count(target)) {
                    //cout<<"->"<<target;
                    currLen++;
                    prev2=prev1;
                    prev1=target;
                    target = prev2 + prev1;
                }
                //cout<<endl;
                maxLen = max(maxLen, currLen);
            }
        }
        return (maxLen < 3) ? 0 : maxLen;
    }
};