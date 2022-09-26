<h2>Articulation Point</h2>

```c++

class ArticulationPoint{
    public:
    int n; 
    vector<vector<int>> adj;
 
    vector<bool> visited,artPoint;
    vector<int> tin, low;
    int timer;
    ArticulationPoint(int _n){
        n = _n;
        timer = 0;
        visited.assign(n+1, false);
        tin.assign(n+1, -1);
        low.assign(n+1, -1);
        artPoint.assign(n+1,false);
        adj.resize(n+1);
    }
    void readGraph(int m){
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    void dfs(int v, int p = -1) {
        visited[v] = true;
        tin[v] = low[v] = timer++;
        int children=0;
        for (int to : adj[v]) {
            if (to == p) continue;
            if (visited[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if (low[to] >= tin[v] && p!=-1){
                    artPoint[v]=true;
                }
                ++children;
            }
        }
        if(p == -1 && children > 1)
            artPoint[v]=true;
    }
 
    int find_cutpoints() {
        int cnt=0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                dfs (i);
            cnt += artPoint[i];
        }
        return cnt;
    }
};

```
