
```c++
class Merge_Sort_Tree{
    public:
    vector<int> v;
    vector<vector<int>> tree;
    int n;
    Merge_Sort_Tree(int _n){
        n=_n;
        v.resize(n+1);
        tree.resize(4*n);
    }
    void Merge(int nd){
        int l = nd*2,r=nd*2+1;
        int n1 = tree[nd*2].size();
        int n2 = tree[nd*2+1].size();
        int i=0,j=0;
        while(i<n1&&j<n2){
            if(tree[l][i]<tree[r][j]){
                tree[nd].push_back(tree[l][i++]);
            }
            else{
                tree[nd].push_back(tree[r][j++]);
            }
        }
        while(i<n1)tree[nd].push_back(tree[l][i++]);
        while(j<n2)tree[nd].push_back(tree[r][j++]);
    }
    void build(int nd, int b, int e){
        if(b>e)return;
        if(b==e){
            tree[nd].push_back(v[b]);
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
            int pos = upper_bound(tree[nd].begin(),tree[nd].end(),k)-tree[nd].begin();
            return tree[nd].size()-pos;
        }
        int m=(b+e)/2;
        int p1 = query(nd*2,b,m,l,r,k);
        int p2 = query(nd*2+1,m+1,e,l,r,k);
        return p1+p2;
    }
};
```
