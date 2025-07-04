class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        
        vector<bool> visited(adj.size(), 0);
        vector<int> distance(adj.size(), -1);
        queue<int> q;
        
        q.push(src);
        
        distance[src] = 0;
        visited[src] = true;
        
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            
            for(auto x : adj[curr])
            {
                if(visited[x] != true){
                q.push(x);
                visited[x] = true;
                distance[x] = distance[curr] + 1;
                }
            }
        }
        
        return distance;
        
    }
};