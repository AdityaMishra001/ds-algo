class Solution {
public:
    vector<int> countServers(const int &n,vector<vector<int>>& logs,const int &x, vector<int>& queries) {
        
        sort(logs.begin(),logs.end(),[](const vector<int>&x,const vector<int>&y){
            return x[1]<y[1];
        });

        //handling queries to get them. in sorted order
        int q=queries.size();
        vector<pair<int,int>>sorted_queries(q);
        for(int id=0;id<q;id++)sorted_queries.emplace_back(queries[id],id);
        sort(sorted_queries.begin(),sorted_queries.end());


        unordered_map<int,int>freq;
        // int activeServers=0;
        int left=0;
        int right=0;
        int Logs=logs.size();

        for(auto&[query,id]:sorted_queries){
            int start=query-x;

            //add logs with time stamp<=q
            while( right<Logs && logs[right][1]<=query){
                int serveId=logs[right][0];
                freq[serveId]++,right++;
            }

            //remove logs with time stamp<start
            while(left<right && logs[left][1]<start){
                int serveId=logs[left][0];
                freq[serveId]--,left++;
                if(freq[serveId]==0)freq.erase(serveId);
            }
            queries[id]=n-freq.size();
        }
        return queries;
    }
};