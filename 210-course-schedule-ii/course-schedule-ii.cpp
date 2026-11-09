class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        for(auto it : prerequisites){
            int u= it[1];
            int v= it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            ans.push_back(q.front());
            q.pop();
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                   q.push(it);
                }
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};