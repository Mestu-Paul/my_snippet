<h2>Articulation Bridge</h2>

```c++

class Find_bridge{
    public:
    int n,Time,m;
    vector<vector<int>>adj;
    vector<bool>visit;
    vector<int>tim,low;
    vector<pair<int,int>> bridges;
    Find_bridge(int _n):n(_n){
        Time=0;
        adj.resize(n+1);
        visit.resize(n+1);
        tim.resize(n+1);
        low.resize(n+1,INT_MAX);
    }
    void readGraph(){
        int a,b;
        cin>>m;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    void dfs(int node, int par){
        tim[node]=low[node]=++Time;
        visit[node]=1;
        for(auto to:adj[node]){
            if(par==to)continue;
            if(visit[to]){
                low[node]=min(low[node],tim[to]);
            }
            else{
                dfs(to,node);
                low[node] = min(low[node],low[to]);
                if(low[to]>tim[node]){
                    bridges.push_back({min(to,node),max(to,node)});
                }
            }
        }
    }
};
```
