```c++


class TreeDiameter{
public:
    int n,leaf,diameter;
    pair<int,int>diameterNodes,center;
    vector<int>dis,parent;
    vector<vector<int>>adj;
    TreeDiameter(int _n){
        n = _n;
        diameter = 0;
        leaf = -1;
        adj.resize(n+1);
        dis.resize(n+1,INT_MAX);
        parent.resize(n+1);
    }
    void readTree(){
        for(int i=1; i<n; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            if(adj[a].size()==1)leaf = a;
            if(adj[b].size()==1)leaf = b;
        }
    }
    void dfs(int node){
        for(auto to:adj[node]){
            if(dis[to] > dis[node]+1){
                dis[to] = dis[node]+1;
                parent[to] = node;
                dfs(to);
            }
        }
    }
    void getMaxDisNode(int &a){
        diameter = 0;
        for(int i=1; i<=n; i++){
            if(diameter < dis[i]){
                diameter = dis[i];
                a = i;
            }
        }
    }
    void findDiemater(){
        if(leaf==-1)return;
        dis[leaf] = 0;
        parent[leaf] = leaf;
        dfs(leaf);
        getMaxDisNode(diameterNodes.first);
        dis.assign(n+1,INT_MAX);
        parent[diameterNodes.first] = diameterNodes.first;
        dis[diameterNodes.first]=0;
        dfs(diameterNodes.first);
        getMaxDisNode(diameterNodes.second);
    }
    void findCenter(){
        if(diameter&1){
            int radius = diameter/2 +1;
            int cur = diameterNodes.second;
            while(dis[cur]!=radius){
                cur = parent[cur];
            }
            center = {cur,parent[cur]};
        }
        else{
            int radius = diameter/2;
            int cur = diameterNodes.second;
            while(dis[cur]!=radius){
                cur = parent[cur];
            }
            center = {cur,cur};
        }
    }
};
```
