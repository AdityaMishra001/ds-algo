class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        vector<int>ct(k,0);
        int maxCt=0;
        

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        >busyServers;

        set<int>freeServers;
        for(int s=0;s<k;s++)
            freeServers.insert(s);

        for(int req_id=0;req_id<n;req_id++){
            int arrTime=arrival[req_id];
            bool processed=false;
            while(!busyServers.empty() && busyServers.top().first<=arrTime){
                freeServers.insert(busyServers.top().second);
                busyServers.pop();
            }
            if(freeServers.size()!=0){
                auto server_id=freeServers.lower_bound(req_id%k);

                if(server_id==freeServers.end())
                    server_id=freeServers.begin();
                int server=*server_id;
                ct[server]++;
                maxCt=max(maxCt,ct[server]);

                busyServers.push({1L*arrTime+load[req_id],server});
                freeServers.erase(server_id);
            }
        }

        vector<int>ans;
        for(int i=0;i<k;i++)
            if(ct[i]==maxCt)
                ans.push_back(i);

        return ans;
    }
};