<h2>Basic</h2>

```c++
#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define vb vector<bool>
#define vs vector<string>
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define ff first
#define ss second
#define bg begin()
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define read(v, a, n) for (int i = a; i<n; i++)cin>>v[i];
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define PI acos(-1.0)
#define yes cout <<"Yes"<< endl
#define no cout<<"No"<<endl
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
#define casep cout<<"Case "<< cs++<<": ";
///................function.....................///

#define D(a) (double)(a)
#define siz(s) (int)(s.size())
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define Min(a) *min_element(all(a))
///#define mod 1000000007
///.........Graph.........///
int X[] = {1, -1, 0, 0};
int Y[] = {0, 0, 1, -1};
///........constant........///
const ll N = 1e6+5;
int main(){
    FIO;

}
```

<h2>Binary Index Tree (BIT)</h2>

```c++
template<class T>
class BIT{
    public:
    int n;
    vector<T> tree;
    BIT(int _n){
        n=_n;
        tree.assign(n+1,0);
    }
    void update(int x, int v){
        while(x<=n){
            tree[x]+=v;
            x += x&(-x);
        }
    }
    T query(int x){
        T sum=0;
        while(x>0){
            sum += tree[x];
            x -= x&(-x);
        }
        return sum;
    }
    T query(int l, int r){
        return query(r)-query(l-1);
    }
};
```

<h2>Decimal to Binary</h2>

```c++
void DecToBin(ll a, vb& bit){
    bit.clear();
    while(a){
        bit.pb(a&1);
        a = a>>1;
    }
    reverse(all(bit));
}
```

<h2>Disjoint Union Set (DSU)</h2>

```c++
class DSU{
    public:
    vi par,sz;
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

<h2>Lowest Common Ancestor (LCA)</h2>

```c++
class Lca{
    public:
    vector<vector<int>> up,g;
    vector<int> depth;
    int n;
    Lca(int _n){
        n = _n;
        up.resize(n+1,vector<int>(19,-1));
        g.resize(n+1);
        depth.resize(n+1);
    }
    void readGraph(int root=1){
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
        for(int i=1; i<19; i++){
            for(int j=1; j<=n; j++){
                if(up[j][i-1]!=-1)
                    up[j][i] = up[up[j][i-1]][i-1];
            }
        }
    }
    int lca_query(int u, int v){
        if(depth[u] < depth[v]) swap(u,v);
        long long diff = depth[u] - depth[v];
        for(long long i = 0; i < 19; i++) if( (diff>>i)&1 ) u = up[u][i];
        if(u == v) return u;
        for(long long i = 19-1; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                    u = up[u][i];
                    v = up[v][i];
            }
        }
        return up[u][0];
    }
};
```

<h2>Merge Sort Tree</h2>

```c++
class Merge_Sort_Tree{
    public:
    vi v;
    vvi tree;
    int n;
    Merge_Sort_Tree(int _n){
        n=_n;
        v.resize(n+1);
        tree.resize(4*n);
    }
    void Merge(int nd){
        int l = nd*2,r=nd*2+1;
        int n1 = siz(tree[nd*2]);
        int n2 = siz(tree[nd*2+1]);
        int i=0,j=0;
        while(i<n1&&j<n2){
            if(tree[l][i]<tree[r][j]){
                tree[nd].pb(tree[l][i++]);
            }
            else{
                tree[nd].pb(tree[r][j++]);
            }
        }
        while(i<n1)tree[nd].pb(tree[l][i++]);
        while(j<n2)tree[nd].pb(tree[r][j++]);
    }
    void build(int nd, int b, int e){
        if(b>e)return;
        if(b==e){
            tree[nd].pb(v[b]);
            return ;
        }
        int m = (b+e)/2;
        build(nd*2,b,m);
        build(nd*2+1,m+1,e);
        Merge(nd);
    }
    int query(int nd, int b, int e, int l, int r, int k){
        if(b>r||e<l)return 0;
        if(l<=b&&e<=r){
            int pos = upper_bound(all(tree[nd]),k)-tree[nd].begin();
            return siz(tree[nd])-pos;
        }
        int m=(b+e)/2;
        int p1 = query(nd*2,b,m,l,r,k);
        int p2 = query(nd*2+1,m+1,e,l,r,k);
        return p1+p2;
    }
};
```

<h2>Segment tree</h2>

```c++
#define lft nd*2
#define rgt nd*2+1
#define mid (b+e)/2
class segtree{
    public:
    int n;
    vector<int> tree,v;
    segtree(int _n, vi& a){
        n=_n;
         v.resize(n+1);
         for(int i=1; i<=n; i++)v[i]=a[i];
        tree.resize(n*4);
    }
    void build(int nd, int b, int e){
        if(b>e)return;
        if(b==e){
            tree[nd]=v[b];
            return;
        }
        build(lft,b,mid);
        build(rgt,mid+1,e);
        tree[nd]=max(tree[lft],tree[rgt]);
    }
    void update(int nd, int b, int e, int l){
        if(b>e or e<l or l<b)return;
        if(b==e and l==b){
            tree[nd]++;
            return;
        }
        update(lft,b,mid,l);
        update(rgt,mid+1,e,l);
        tree[nd]=tree[lft]+tree[rgt];
    }
    int query(int nd, int b, int e, int l, int r){
        if(b>e or e<l or r<b)return 0;
        if(l<=b and e<=r){
            return tree[nd];
        }
        int p1 = query(lft,b,mid,l,r);
        int p2 = query(rgt,mid+1,e,l,r);
        return p1+p2;
    }
};
```
<h2>Sieve</h2>

```c++
ll prime_size=1e6+5;
vi primes;
vb mark(prime_size);
void sieve(){
    ll i,j;
    for(i=3; i*i<=prime_size; i+=2){
        if(!mark[i]){
            for(j=i*i; j<=prime_size; j+=i*2)mark[j]=1;
        }
    }
    primes.pb(2);
    for(i=3; i<=N; i+=2)if(!mark[i])primes.pb(i);
}
```

<h2>Tree (DFS) </h2>

```c++
class graph{
public:
    vector<vector<int>> g;
    int n;
    graph(int _n){
        n=_n;
        g.resize(n+1);
    }
    void readGraph(){
        int a,b;
        for(int i=1; i<n; i++){
            cin>>a>>b;
            g[a].pb(b);
            g[b].pb(a);
        }
    }
    void dfs(int nd, int par){
        for(auto to:g[nd]){
            if(to==par)continue;
            dfs(to,nd);
        }
    }
};
```



