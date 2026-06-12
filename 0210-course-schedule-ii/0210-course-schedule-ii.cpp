class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        vector<int>sequence;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            sequence.push_back(node);
            for(auto neighbour: adj[node]){
                indegree[neighbour]--;
                if(!indegree[neighbour]){
                    q.push(neighbour);
                }
            }
        }
        if(sequence.size()==numCourses)
            return sequence;
        return {};    
    }
};