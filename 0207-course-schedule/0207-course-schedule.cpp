class Solution {
public:
    bool DFS(int i,vector<vector<int>>& adj, vector<int>&isVisited, vector<int>&pathVisited){
        isVisited[i] = 1;
        pathVisited[i] = 1;
        for(auto x : adj[i]){
            if(!isVisited[x]) {
                if(!DFS(x, adj, isVisited, pathVisited)) return false;
            }
            
            else if(pathVisited[x]) {
                return false;
            }
        }
        pathVisited[i] = 0; 
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]); 
        }
        vector<int>isVisited(numCourses,0);
        vector<int>pathVisited(numCourses,0);
        for(int i = 0;i<numCourses;i++){
            if(isVisited[i]) continue;
            if(!DFS(i,adj,isVisited,pathVisited)) return false;
        }
        return true;
    }
};















// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> adj[numCourses];
//         for (auto it : prerequisites) {
//             adj[it[1]].push_back(it[0]);
//         }
//         vector<int>indegree(numCourses,0);
//         for (int i = 0; i < numCourses; i++) {
//             for (auto it : adj[i]) {
//                 indegree[it]++;
//             }
//         }
//         queue<int> q;
//         for (int i = 0; i < numCourses; i++) {
//             if (indegree[i] == 0)
//                 q.push(i);
//         }
//         vector<int> topo;
//         while (!q.empty()) {
//             int node = q.front();
//             q.pop();
//             topo.push_back(node);
//             for (auto it : adj[node]) {
//                 indegree[it]--;
//                 if (indegree[it] == 0)
//                     q.push(it);
//             }
//         }
//         if (topo.size() == numCourses)
//             return true;
//         return false;
//     }
// };