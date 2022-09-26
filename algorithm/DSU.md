<h2>DSU</h2>

```c++
class DSU{
    public:
    vector<int> par,sz;
    int n;
    DSU(int _n){
        n=_n;
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=1; i<=n; i++)par[i]=i,sz[i]=1;
    }
    int Find(int a){
        if(a==par[a])return par[a];
        return par[a] = Find(par[a]);
    }
    void Union(int a, int b){
        a = Find(a);b = Find(b);
        if(a==b)return;
        if(sz[a]>=sz[b]){
            sz[a]+=sz[b];
            par[b]=a;
        }
        else{
            par[a]=b;
            sz[b]+=sz[a];
        }
    }
};

```
