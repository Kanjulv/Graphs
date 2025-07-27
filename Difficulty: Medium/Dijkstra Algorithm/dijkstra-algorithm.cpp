// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        //Create adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        //Creating the ans vector
        vector<int> dist(V, INT_MAX);
        
        //Create a set
        set<pair<int,int>> st;
        
        dist[src] = 0;
        st.insert(make_pair(0, src));
        
        while(!st.empty())
        {
            auto top = *(st.begin());
            
            int topNode = top.second;
            int topDist = top.first;
            
            //Erase as soon as the node is evaluated
            st.erase(st.begin());
            
            for(auto neighbour: adj[topNode])
            {
                if(topDist + neighbour.second < dist[neighbour.first])
                {
                    //Check if already exists in the set
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    
                    if(record != st.end())
                    {
                        st.erase(record);
                    }
                    
                    dist[neighbour.first] = topDist + neighbour.second;
                    
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
        
        return dist;
    }
};