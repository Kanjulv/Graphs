class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int spanningTree(int V, vector<vector<int>> edges[]) {
        
        //Creating Adjacency list
      unordered_map<int, list<pair<int, int>>> adj;
        
for (int u = 0; u < V; ++u) {
        // Iterate through each 'edge' connected to node 'u'
        // Each 'edge' here is a vector like {neighbor_node, weight}
        for (const auto& neighbor_info : edges[u]) {
            int v = neighbor_info[0];
            int weight = neighbor_info[1];
            adj[u].push_back({v, weight});
            // Since it's an undirected graph, add the reverse edge as well
            adj[v].push_back({u, weight});
        }
    }
    
        vector<int> key(V, INT_MAX);
        vector<bool> mst(V, false);
        vector<int> parent(V, -1);
        
        key[0] = 0;
        
        for(int i = 0; i < V; i++)
        {
            int mini = INT_MAX;
            int u;
            
            for(int v = 0; v < V; v++)
            {
            
            if(key[v] < mini && mst[v] == false) {
                
            mini = key[v];
            u = v;
            }
            }
            
            mst[u] = true;
            
            for(auto x: adj[u])
            {
                int node = x.first;
                int wt = x.second;
                
                if(key[node] > wt && mst[node] == false)
                {
                    key[node] = wt;
                    parent[node] = u;
                }
            }
        }
        
        int sum = 0;
        for(int i = 0; i < V; i++)
        {
            sum += key[i];
        }
        
        return sum;
    }
};