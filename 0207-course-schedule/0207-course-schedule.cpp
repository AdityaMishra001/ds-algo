class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        queue<int>q;
        vector<int>indegree(numCourses);

        for(auto p:prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        int coursesCompleted=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            coursesCompleted++;
            for(auto neighbour: adj[node]){
                indegree[neighbour]--;
                if(!indegree[neighbour]){
                    q.push(neighbour);
                }
            }
        }
        return (coursesCompleted==numCourses)? 1:0;
    }
};