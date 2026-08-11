class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adjList[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>>store;
        store.push({0,{src,0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!store.empty()){
            auto x = store.front();
            store.pop();
            int stop = x.first;
            int node = x.second.first;
            int cost = x.second.second;
            
            if(stop>k) continue;
            for(auto it : adjList[node]){
                int n = it.first;
                int ct = it.second;
                if(ct+cost < dist[n] && stop<=k){
                    dist[n] = ct+cost;
                    store.push({stop+1,{n,ct+cost}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        else return dist[dst];

    }
};