<h2> Lowest Common Ancestor</h2>

```c++

const int Log=15;
class Lca{
    public:
    vector<vector<int>> up,g;
    vector<int> depth;
    int n;
    Lca(int _n){
        n = _n;
        up.resize(n+1,vector<int>(Log,-1));
        g.resize(n+1);
        depth.resize(n+1);
    }
    void readTree(int root=1){
        int a,b;
        for(int i=1; i<n; i++){
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(root,root,0);
        cal_sparse_table();
    }
    void dfs(int nd, int par, int d){
        depth[nd]=d,up[nd][0]=par;
        for(auto to:g[nd]){
            if(to==par)continue;
            dfs(to,nd,d+1);
        }
    }
    void cal_sparse_table(){
        for(int i=1; i<Log; i++){
            for(int j=1; j<=n; j++){
                if(up[j][i-1]!=-1)
                    up[j][i] = up[up[j][i-1]][i-1];
            }
        }
    }
    int lca_query(int u, int v){
        if(depth[u] < depth[v]) swap(u,v);
        long long diff = depth[u] - depth[v];
        for(long long i = 0; i < Log; i++) if( (diff>>i)&1 ) u = up[u][i];
        if(u == v) return u;
        for(long long i = Log-1; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                    u = up[u][i];
                    v = up[v][i];
            }
        }
        return up[u][0];
    }
   int x_thParent(int u, int x){
       for(long long i = 0; i < Log; i++) if( (x>>i)&1 ) u = up[u][i];
       return u;
   }
   int cal_dis(int a, int b, int l){
       return depth[a]+depth[b] - depth[l]*2;
   }
};

```
