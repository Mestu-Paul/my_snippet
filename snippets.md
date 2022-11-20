
<details>
	<summary>Main</summary>
	<b>Code</b>

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
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

//#define mod 1000000007
//........constant........///
const ll N = 1e6+5;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
int main(){
    FIO;
    file();

}
```
	
<b>vs code</b>
	
```
{
	"For basic template":{
		"prefix": "basic",
		"body": [
			"#include <bits/stdc++.h>",
			"using namespace std;",
			
			"//#include<ext/pb_ds/assoc_container.hpp>",
			"//#include<ext/pb_ds/tree_policy.hpp>",
			"//using namespace __gnu_pbds;",
			"//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key",
			"#define ll long long",
			"#define vi vector<int>",
			"#define pii pair<int, int>",
			"#define pll pair<ll, ll>",
			"#define vvi vector<vi>",
			"#define vll vector<ll>",
			"#define vvll vector<vector<ll>>",
			"#define vpii vector<pair<int,int>>",
			"#define vpll vector<pair<ll,ll>>",
			"int Set(int N, int pos) {return  N = N | (1<<pos);}",
			"int Reset(int N, int pos) {return  N = N & ~(1<<pos);}",
			"bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}",
			"///............x...........///",
			"#define all(a) a.begin(), a.end()",
			"#define allr(a) a.rbegin(), a.rend()",
			"#define mp(a, b) make_pair(a, b)",
			"#define pb push_back",
			"#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())",
			"#define ft cout << \"for test\"<<endl;",
			"#define print(v) for (auto it : v)cout << it<<\" \";cout << endl;",
			"#define PI acos(-1.0)",
			"#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);",
			"#define t_c int test, cs = 1;cin>>test;while (test--)",
			"///................function.....................///\n",
			"//#define mod 1000000007",
			"//........constant........///",
			"const ll N = 1e6+5;",
			"void file(){",
			"   freopen(\"input.txt\",\"r\",stdin);",
			"   freopen(\"output.txt\",\"w\",stdout);",
			"}",
			"int main(){",
			"\tFIO;",
			"\tfile();\n$0",
			"}",
		],
		"description": "nothing",
	}
}
```
</details>

<details>
  <summary>Trie</summary>
  <b>Code</b>
  
  ```c++
  class Trie{
      struct node{
          node* next[26];
          int finishedCount;
          int numberOfVisit;
          node(){
              for(int i=0; i<26; i++){
                  next[i]=NULL;
              }
              finishedCount=numberOfVisit=0;
          }
      };
      node* root=new node();
      public:
      Trie(){}
      void addString(string& s, char lowestChar='a'){
          node* head=root;
          for(auto x:s){
              if(head->next[x-lowestChar]==NULL){
                  head->next[x-lowestChar]=new node();
              }
              head = head->next[x-lowestChar];
              head->numberOfVisit++;
          }
          head->finishedCount++;
      }
      void queryString(string &s, int l, int r, char lowestChar='a'){
          node* head = root;
          for(int i=l; i<=r; i++){
              char x = s[i];
              if(head->next[x-lowestChar]==NULL)break;
              head = head->next[x-lowestChar];
              ache[l][i]+=head->finishedCount;
          }
      }
  };
  ```

  <b> VS code </b>

  ```
  {
    "Data Structer":{
      "prefix":"Trie",
      "body": [
        "class Trie{",
        "    struct node{",
        "        node* next[26];",
        "        int finishedCount;",
        "        int numberOfVisit;",
        "        node(){",
        "            for(int i=0; i<26; i++){",
        "                next[i]=NULL;",
        "            }",
        "            finishedCount=numberOfVisit=0;",
        "        }",
        "    };",
        "    node* root=new node();",
        "    public:",
        "    Trie(){}",
        "    void addString(string& s, char lowestChar='a'){",
        "        node* head=root;",
        "        for(auto x:s){",
        "            if(head->next[x-lowestChar]==NULL){",
        "                head->next[x-lowestChar]=new node();",
        "            }",
        "            head = head->next[x-lowestChar];",
        "            head->numberOfVisit++;",
        "        }",
        "        head->finishedCount++;",
        "    }",
        "    void queryString(string &s, int l, int r, char lowestChar='a'){",
        "        node* head = root;",
        "        for(int i=l; i<=r; i++){",
        "            char x = s[i];",
        "            if(head->next[x-lowestChar]==NULL)break;",
        "            head = head->next[x-lowestChar];",
        "            ache[l][i]+=head->finishedCount;",
        "        }",
        "    }",
        "};",

      ],
    }
  }
  ```
</details>
  
<details>
  <summary>Z_function</summary>
  
  <b>Code</b>
  
  ```c++
  
    class Z_Function{
      string s;
      int n;
      public:
      Z_Function(string& s){
          this->s=s;
          n=s.size();
      }
      void generate(vector<int>&z) {
          for (int i = 1, l = 0, r = 0; i < n; ++i) {
              if (i <= r)
                  z[i] = min (r - i + 1, z[i - l]);
              while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                  ++z[i];
              if (i + z[i] - 1 > r)
                  l = i, r = i + z[i] - 1;
          }
      }
  };
  ```

  <b> VS code </b>

  ```
      {
      "String function":{
        "prefix": "Z_algo",
        "body": [
          "class Z_Function{",
          "    string s;",
          "    int n;",
          "    public:",
          "    Z_Function(string& s){",
          "        this->s=s;",
          "        n=s.size();",
          "    }",
          "    void generate(vector<int>&z) {",
          "        for (int i = 1, l = 0, r = 0; i < n; ++i) {",
          "            if (i <= r)",
          "                z[i] = min (r - i + 1, z[i - l]);",
          "            while (i + z[i] < n && s[z[i]] == s[i + z[i]])",
          "                ++z[i];",
          "            if (i + z[i] - 1 > r)",
          "                l = i, r = i + z[i] - 1;",
          "        }",
          "    }",
          "};",

        ],
      }
    }
  ```
</details>
  
<details>
  <summary>Bellman</summary>
  <b>Code</b>
  
  ```c++
  class BellmanFord{
    public:
    int n,m;
    vector<pair<int,pair<int,int>>> edges;
    vector<int>parent;
    vector<long long>dis;
    BellmanFord(int _n, int _m){
        n = _n;
        m = _m;
        parent.resize(n+1);
        dis.assign(n+1,1LL<<62);
    }
    void readGraph(){
        for(int i=0; i<m; i++){
            int a,b,c;
            cin>>a>>b>>c;
            edges.pb({c,{a,b}});
        }
    }
    vi findNegCycle(){
        int lastNode=-1;
        dis[1]=0;
        for(int i=0; i<=n; i++){
            lastNode = -1;
            for(auto x:edges){
                int a=x.second.first;
                int b=x.second.second;
                ll  c=x.first;
                if(dis[b]>dis[a]+c){
                    dis[b]=dis[a]+c;
                    lastNode=b;
                    parent[b]=a;
                }
            }
        }
        vi res;
        if(lastNode==-1)return res;
        for(int i=0; i<n; i++)lastNode=parent[lastNode];
        for(int y=lastNode; ;y=parent[y]){
            res.pb(y);
            if(y==lastNode and res.size()>1)break;
        }
        return res;
    }

};
  ```

  <b> VS code </b>

  ```
  {
	"Bellman":{
		"prefix": "Bellman",
		"body": [
			"class BellmanFord{",
			"    public:",
			"    int n,m;",
			"    vector<pair<int,pair<int,int>>> edges;",
			"    vector<int>parent;",
			"    vector<long long>dis;",
			"    BellmanFord(int _n, int _m){",
			"        n = _n;",
			"        m = _m;",
			"        parent.resize(n+1);",
			"        dis.assign(n+1,1LL<<62);",
			"    }",
			"    void readGraph(){",
			"        for(int i=0; i<m; i++){",
			"            int a,b,c;",
			"            cin>>a>>b>>c;",
			"            edges.pb({c,{a,b}});",
			"        }",
			"    }",
			"    vi findNegCycle(){",
			"        int lastNode=-1;",
			"        dis[1]=0;",
			"        for(int i=0; i<=n; i++){",
			"            lastNode = -1;",
			"            for(auto x:edges){",
			"                int a=x.second.first;",
			"                int b=x.second.second;",
			"                ll  c=x.first;",
			"                if(dis[b]>dis[a]+c){",
			"                    dis[b]=dis[a]+c;",
			"                    lastNode=b;",
			"                    parent[b]=a;",
			"                }",
			"            }",
			"        }",
			"        vi res;",
			"        if(lastNode==-1)return res;",
			"        for(int i=0; i<n; i++)lastNode=parent[lastNode];",
			"        for(int y=lastNode; ;y=parent[y]){",
			"            res.pb(y);",
			"            if(y==lastNode and res.size()>1)break;",
			"        }",
			"        return res;",
			"    }",
			"",
			"};",

		],
	}
}
  ```
</details>
	
<details>
  <summary>binary indexed tree</summary>
  <b>Code</b>
  
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

  <b> VS code </b>

  ```
  {
	"Binary index tree":{
		"prefix": "BIT",
		"body": [
			"template<class T>",
			"class BIT{",
			"    public:",
			"    int n;",
			"    vector<T> tree;",
			"    BIT(int _n){",
			"        n=_n;",
			"        tree.assign(n+1,0);",
			"    }",
			"    void update(int x, int v){",
			"        while(x<=n){",
			"            tree[x]+=v;",
			"            x += x&(-x);",
			"        }",
			"    }",
			"    T query(int x){",
			"        T sum=0;",
			"        while(x>0){",
			"            sum += tree[x];",
			"            x -= x&(-x);",
			"        }",
			"        return sum;",
			"    }",
			"    T query(int l, int r){",
			"        return query(r)-query(l-1);",
			"    }",
			"};",
		],
		"description": "binary index tree",
	}
}
  ```
</details>

<details>
  <summary>DSU</summary>
  <b>Code</b>
  
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

  <b> VS code </b>

  ```
  {
	"DSU":{
		"prefix":"DSU",
		"body":[
			"class DSU{",
			"    public:",
			"    vi par,sz;",
			"    int n;",
			"    DSU(int _n){",
			"        n=_n;",
			"        par.resize(n+1);",
			"        sz.resize(n+1);",
			"        for(int i=1; i<=n; i++)par[i]=i,sz[i]=1;",
			"    }",
			"    int Find(int a){",
			"        if(a==par[a])return par[a];",
			"        return par[a] = Find(par[a]);",
			"    }",
			"    void Union(int a, int b){",
			"        a = Find(a);b = Find(b);",
			"        if(a==b)return;",
			"        if(sz[a]>=sz[b]){",
			"            sz[a]+=sz[b];",
			"            par[b]=a;",
			"        }",
			"        else{",
			"            par[a]=b;",
			"            sz[b]+=sz[a];",
			"        }",
			"    }",
			"};",

		],
	}
}
  ```
</details>

<details>
  <summary>Finding Bridge</summary>
  <b>Code</b>
  
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

  <b> VS code </b>

  ```
  {
	"Finding Bridge":{
		"prefix":"Find_Bridge",
		"body": [
			"class Find_bridge{",
			"    public:",
			"    int n,Time,m;",
			"    vector<vector<int>>adj;",
			"    vector<bool>visit;",
			"    vector<int>tim,low;",
			"    vector<pair<int,int>> bridges;",
			"    Find_bridge(int _n):n(_n){",
			"        Time=0;",
			"        adj.resize(n+1);",
			"        visit.resize(n+1);",
			"        tim.resize(n+1);",
			"        low.resize(n+1,INT_MAX);",
			"    }",
			"    void readGraph(){",
			"        int a,b;",
			"        cin>>m;",
			"        for(int i=0; i<m; i++){",
			"            cin>>a>>b;",
			"            adj[a].push_back(b);",
			"            adj[b].push_back(a);",
			"        }",
			"    }",
			"    void dfs(int node, int par){",
			"        tim[node]=low[node]=++Time;",
			"        visit[node]=1;",
			"        for(auto to:adj[node]){",
			"            if(par==to)continue;",
			"            if(visit[to]){",
			"                low[node]=min(low[node],tim[to]);",
			"            }",
			"            else{",
			"                dfs(to,node);",
			"                low[node] = min(low[node],low[to]);",
			"                if(low[to]>tim[node]){",
			"                    bridges.push_back({min(to,node),max(to,node)});",
			"                }",
			"            }",
			"        }",
			"    }",
			"};",
		],
	}

}
  ```
</details>

<details>
  <summary>Double  hash</summary>
  <b>Code</b>
  
  ```c++
  #define mod1 2038074743
#define base1 117671
#define mod2 1000000007
#define base2 443
class Hash_table{
    public:
    string s;
    vll hash1,hash2,pow1,pow2;
    int n;
    Hash_table(string& s){
        this->s=s;
        n=s.size();
        hash1 = vll(n);
        hash2 = vll(n);
        pow1 = vll(n+1,1);
        pow2 = vll(n+1,1);
    }
    void gen_hash(){
        for(int i=1; i<=n; i++){
            pow1[i]=(pow1[i-1]*base1)%mod1;
            pow2[i]=(pow2[i-1]*base2)%mod2;
        }
        ll cur1=0,cur2=0;
        for(int i=0; i<n; i++){
            cur1 = (cur1*base1 + (s[i]-'a'+1))%mod1;
            cur2 = (cur2*base2 + (s[i]-'a'+1))%mod2;
            hash1[i]=cur1;
            hash2[i]=cur2;
        }
    }
    bool isMatched(int l1, int r1, int l2, int r2){
        if(r1<l1 or r2<l2 or r1-l1!=r2-l2)return false;
        ll len=r1-l1+1;
        ll h11 = (l1==0)?hash1[r1]:((hash1[r1]-hash1[l1-1]*pow1[len])%mod1+mod1)%mod1;
        ll h12 = (l1==0)?hash2[r1]:((hash2[r1]-hash2[l1-1]*pow2[len])%mod2+mod2)%mod2;
        ll h21 = (l2==0)?hash1[r2]:((hash1[r2]-hash1[l2-1]*pow1[len])%mod1+mod1)%mod1;
        ll h22 = (l2==0)?hash2[r2]:((hash2[r2]-hash2[l2-1]*pow2[len])%mod2+mod2)%mod2;
        if(h11==h21 and h12==h22)return true;
        return false;
    }
};
  ```

  <b> VS code </b>

  ```
  {
	"hash":{
		"prefix": "hash",
		"body": [
			"#define mod1 2038074743",
			"#define base1 117671",
			"#define mod2 1000000007",
			"#define base2 443",
			"class Hash_table{",
			"    public:",
			"    string s;",
			"    vll hash1,hash2,pow1,pow2;",
			"    int n;",
			"    Hash_table(string& s){",
			"        this->s=s;",
			"        n=s.size();",
			"        hash1 = vll(n);",
			"        hash2 = vll(n);",
			"        pow1 = vll(n+1,1);",
			"        pow2 = vll(n+1,1);",
			"    }",
			"    void gen_hash(){",
			"        for(int i=1; i<=n; i++){",
			"            pow1[i]=(pow1[i-1]*base1)%mod1;",
			"            pow2[i]=(pow2[i-1]*base2)%mod2;",
			"        }",
			"        ll cur1=0,cur2=0;",
			"        for(int i=0; i<n; i++){",
			"            cur1 = (cur1*base1 + (s[i]-'a'+1))%mod1;",
			"            cur2 = (cur2*base2 + (s[i]-'a'+1))%mod2;",
			"            hash1[i]=cur1;",
			"            hash2[i]=cur2;",
			"        }",
			"    }",
			"    bool isMatched(int l1, int r1, int l2, int r2){",
			"        if(r1<l1 or r2<l2 or r1-l1!=r2-l2)return false;",
			"        ll len=r1-l1+1;",
			"        ll h11 = (l1==0)?hash1[r1]:((hash1[r1]-hash1[l1-1]*pow1[len])%mod1+mod1)%mod1;",
			"        ll h12 = (l1==0)?hash2[r1]:((hash2[r1]-hash2[l1-1]*pow2[len])%mod2+mod2)%mod2;",
			"        ll h21 = (l2==0)?hash1[r2]:((hash1[r2]-hash1[l2-1]*pow1[len])%mod1+mod1)%mod1;",
			"        ll h22 = (l2==0)?hash2[r2]:((hash2[r2]-hash2[l2-1]*pow2[len])%mod2+mod2)%mod2;",
			"        if(h11==h21 and h12==h22)return true;",
			"        return false;",
			"    }",
			"};",

		],
		"description": "hash generate and matching",
	}
}
  ```
</details>

<details>
  <summary>KMP</summary>
  <b>Code</b>
  
  ```c++
  class KMP{
    public:
    int n,m;
    string text,pattern;
    vector<int> lps;
    KMP(string& _text, string& _pattern){
        text=_text;
        pattern=_pattern;
        n = text.size();
        m = pattern.size();
        lps.resize(m);
    }
    void lps_gen(){
        int i=1,index=0;
        while(i<m){
            if(pattern[i]==pattern[index]){
                lps[i++]=++index;
            }
            else{
                if(index>0)index = lps[index-1];
                else i++;
            }
        }
    }
    void kmp(vector<int>&ans){
        int i,index=0;
        for(i=0; i<n; i++){
            if(text[i]==pattern[index]){
                index++;
            }
            else if(index>0){
                index = lps[index-1];
                i--;
            }
            if(index==m){
                ans.push_back(i-index+2);
                index = lps[index-1];
            }
        }
    }
};
  ```

  <b> VS code </b>

  ```
  {
	"string algorithm":{
		"prefix":"kmp",
		"body": [
			"class KMP{",
			"    public:",
			"    int n,m;",
			"    string text,pattern;",
			"    vector<int> lps;",
			"    KMP(string& _text, string& _pattern){",
			"        text=_text;",
			"        pattern=_pattern;",
			"        n = text.size();",
			"        m = pattern.size();",
			"        lps.resize(m);",
			"    }",
			"    void lps_gen(){",
			"        int i=1,index=0;",
			"        while(i<m){",
			"            if(pattern[i]==pattern[index]){",
			"                lps[i++]=++index;",
			"            }",
			"            else{",
			"                if(index>0)index = lps[index-1];",
			"                else i++;",
			"            }",
			"        }",
			"    }",
			"    void kmp(vector<int>&ans){",
			"        int i,index=0;",
			"        for(i=0; i<n; i++){",
			"            if(text[i]==pattern[index]){",
			"                index++;",
			"            }",
			"            else if(index>0){",
			"                index = lps[index-1];",
			"                i--;",
			"            }",
			"            if(index==m){",
			"                ans.push_back(i-index+2);",
			"                index = lps[index-1];",
			"            }",
			"        }",
			"    }",
			"};",
		],
	}
}
  ```
</details>

<details>
  <summary>LCA</summary>
  <b>Code</b>
  
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

  <b> VS code </b>

  ```
  {
	"lowest common ancestor":{
		"prefix": "LCA",
		"body":[
			"const int Log=15;",
			"class Lca{",
			"    public:",
			"    vector<vector<int>> up,g;",
			"    vector<int> depth;",
			"    int n;",
			"    Lca(int _n){",
			"        n = _n;",
			"        up.resize(n+1,vector<int>(Log,-1));",
			"        g.resize(n+1);",
			"        depth.resize(n+1);",
			"    }",
			"    void readTree(int root=1){",
			"        int a,b;",
			"        for(int i=1; i<n; i++){",
			"            cin>>a>>b;",
			"            g[a].push_back(b);",
			"            g[b].push_back(a);",
			"        }",
			"        dfs(root,root,0);",
			"        cal_sparse_table();",
			"    }",
			"    void dfs(int nd, int par, int d){",
			"        depth[nd]=d,up[nd][0]=par;",
			"        for(auto to:g[nd]){",
			"            if(to==par)continue;",
			"            dfs(to,nd,d+1);",
			"        }",
			"    }",
			"    void cal_sparse_table(){",
			"        for(int i=1; i<Log; i++){",
			"            for(int j=1; j<=n; j++){",
			"                if(up[j][i-1]!=-1)",
			"                    up[j][i] = up[up[j][i-1]][i-1];",
			"            }",
			"        }",
			"    }",
			"    int lca_query(int u, int v){",
			"        if(depth[u] < depth[v]) swap(u,v);",
			"        long long diff = depth[u] - depth[v];",
			"        for(long long i = 0; i < Log; i++) if( (diff>>i)&1 ) u = up[u][i];",
			"        if(u == v) return u;",
			"        for(long long i = Log-1; i >= 0; i--) {",
			"            if(up[u][i] != up[v][i]) {",
			"                    u = up[u][i];",
			"                    v = up[v][i];",
			"            }",
			"        }",
			"        return up[u][0];",
			"    }",
			"   int x_thParent(int u, int x){",
			"       for(long long i = 0; i < Log; i++) if( (x>>i)&1 ) u = up[u][i];",
			"       return u;",
			"   }",
			"   int cal_dis(int a, int b, int l){",
			"       return depth[a]+depth[b] - depth[l]*2;",
			"   }",
			"};",
		],
		"description": "lowest common ancestor",
	}
}

  ```
</details>
	
<details>
  <summary>Merge sort tree</summary>
  <b>Code</b>
  
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
        int n1 = (int)(tree[nd*2].size());
        int n2 = (int)(tree[nd*2+1].size());
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
            return (int)(tree[nd].size())-pos;
        }
        int m=(b+e)/2;
        int p1 = query(nd*2,b,m,l,r,k);
        int p2 = query(nd*2+1,m+1,e,l,r,k);
        return p1+p2;
    }
};
  ```

  <b> VS code </b>

  ```
  {
	"Merge sort tree":{
		"prefix": "Merge sort tree",
		"body": [
			"class Merge_Sort_Tree{",
			"    public:",
			"    vector<int> v;",
			"    vector<vector<int>> tree;",
			"    int n;",
			"    Merge_Sort_Tree(int _n){",
			"        n=_n;",
			"        v.resize(n+1);",
			"        tree.resize(4*n);",
			"    }",
			"    void Merge(int nd){",
			"        int l = nd*2,r=nd*2+1;",
			"        int n1 = (int)(tree[nd*2].size());",
			"        int n2 = (int)(tree[nd*2+1].size());",
			"        int i=0,j=0;",
			"        while(i<n1&&j<n2){",
			"            if(tree[l][i]<tree[r][j]){",
			"                tree[nd].push_back(tree[l][i++]);",
			"            }",
			"            else{",
			"                tree[nd].push_back(tree[r][j++]);",
			"            }",
			"        }",
			"        while(i<n1)tree[nd].push_back(tree[l][i++]);",
			"        while(j<n2)tree[nd].push_back(tree[r][j++]);",
			"    }",
			"    void build(int nd, int b, int e){",
			"        if(b>e)return;",
			"        if(b==e){",
			"            tree[nd].push_back(v[b]);",
			"            return ;",
			"        }",
			"        int m = (b+e)/2;",
			"        build(nd*2,b,m);",
			"        build(nd*2+1,m+1,e);",
			"        Merge(nd);",
			"    }",
			"    int query(int nd, int b, int e, int l, int r, int k){",
			"        if(b>r||e<l)return 0;",
			"        if(l<=b&&e<=r){",
			"            int pos = upper_bound(tree[nd].begin(),tree[nd].end(),k)-tree[nd].begin();",
			"            return (int)(tree[nd].size())-pos;",
			"        }",
			"        int m=(b+e)/2;",
			"        int p1 = query(nd*2,b,m,l,r,k);",
			"        int p2 = query(nd*2+1,m+1,e,l,r,k);",
			"        return p1+p2;",
			"    }",
			"};",
		],
		"description": "implemented class merge sort tree",
	}
}
  ```
</details>
	
<details>
  <summary>SCC</summary>
  <b>Code</b>
  
  ```c++
  class SCC{
    public:
    vector<int>order,component;
    vector<bool> used;
    int n,rt;
    vector<vector<int>>adj,adj_rev;
    vi root;
    SCC(int _n){
        n = _n;
        rt=0;
        root.resize(n+1);
        used = vector<bool>(n+1);
        adj = adj_rev = vector<vector<int>>(n+1);
    }
    void readGraph(int m){
        for(int i=0; i<m; i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj_rev[b].push_back(a);
        }
    }
    void dfs1(int nd){
        used[nd] = true;
        for(auto v:adj[nd]){
            if(!used[v]){
                dfs1(v);
            }
        }
        order.push_back(nd);
    }
    void dfs2(int nd){
        root[nd] = rt;
        used[nd] = true;
        for(auto v:adj_rev[nd]){
            if(!used[v]){
                dfs2(v);
            }
        }
    }
    void call_all_function(){
        for(int i=1; i<=n; i++){
            if(!used[i]){
                dfs1(i);
            }
        }
        used = vector<bool>(n+1,false);
        reverse(all(order));
        for(auto i:order){
            if(!used[i]){
                ++rt;
                dfs2(i);
            }
        }
    }
};
  ```

  <b> VS code </b>

  ```
  {
	"Strongly Connected Component": {
		"prefix": "SCC",
		"body": [
			"class SCC{",
			"    public:",
			"    vector<int>order,component;",
			"    vector<bool> used;",
			"    int n,rt;",
			"    vector<vector<int>>adj,adj_rev;",
			"    vi root;",
			"    SCC(int _n){",
			"        n = _n;",
			"        rt=0;",
			"        root.resize(n+1);",
			"        used = vector<bool>(n+1);",
			"        adj = adj_rev = vector<vector<int>>(n+1);",
			"    }",
			"    void readGraph(int m){",
			"        for(int i=0; i<m; i++){",
			"            int a,b;",
			"            cin>>a>>b;",
			"            adj[a].push_back(b);",
			"            adj_rev[b].push_back(a);",
			"        }",
			"    }",
			"    void dfs1(int nd){",
			"        used[nd] = true;",
			"        for(auto v:adj[nd]){",
			"            if(!used[v]){",
			"                dfs1(v);",
			"            }",
			"        }",
			"        order.push_back(nd);",
			"    }",
			"    void dfs2(int nd){",
			"        root[nd] = rt;",
			"        used[nd] = true;",
			"        for(auto v:adj_rev[nd]){",
			"            if(!used[v]){",
			"                dfs2(v);",
			"            }",
			"        }",
			"    }",
			"    void call_all_function(){",
			"        for(int i=1; i<=n; i++){",
			"            if(!used[i]){",
			"                dfs1(i);",
			"            }",
			"        }",
			"        used = vector<bool>(n+1,false);",
			"        reverse(all(order));",
			"        for(auto i:order){",
			"            if(!used[i]){",
			"                ++rt;",
			"                dfs2(i);",
			"            }",
			"        }",
			"    }",
			"};",


		],
		"description": "Strongly Connected Component",
	}
}
  ```
</details>
	
<details>
	<summary>segment tree</summary>
	<b>Code</b>

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
	
<b>vs code</b>
	
```
{
	"SegmentTree":{
		"prefix": "segTree",
		"body": [
			"#define lft nd*2",
			"#define rgt nd*2+1",
			"#define mid (b+e)/2",
			"class segtree{",
			"    public:",
			"    int n;",
			"    vector<int> tree,v;",
			"    segtree(int _n, vi& a){",
			"        n=_n;",
			"		 v.resize(n+1);",
			"		 for(int i=1; i<=n; i++)v[i]=a[i];",
			"        tree.resize(n*4);",
			"    }",
			"	void build(int nd, int b, int e){",
			"		if(b>e)return;",
			"		if(b==e){",
			"			tree[nd]=v[b];",
			"			return;",
			"		}",
			"		build(lft,b,mid);",
			"		build(rgt,mid+1,e);",
			"		tree[nd]=max(tree[lft],tree[rgt]);",
			"	}",
			"    void update(int nd, int b, int e, int l){",
			"        if(b>e or e<l or l<b)return;",
			"        if(b==e and l==b){",
			"            tree[nd]++;",
			"            return;",
			"        }",
			"        update(lft,b,mid,l);",
			"        update(rgt,mid+1,e,l);",
			"        tree[nd]=tree[lft]+tree[rgt];",
			"    }",
			"    int query(int nd, int b, int e, int l, int r){",
			"        if(b>e or e<l or r<b)return 0;",
			"        if(l<=b and e<=r){",
			"            return tree[nd];",
			"        }",
			"        int p1 = query(lft,b,mid,l,r);",
			"        int p2 = query(rgt,mid+1,e,l,r);",
			"        return p1+p2;",
			"    }",
			"};",
		],
		"description": "basic seg tree implement",
	}
}
```
	
</details>

<details>
	<summary>String factorization</summary>
	<b>Code</b>

```c++
class LyndonFactorization
{
public:
    vector<string> duval(string const &s)
    {
        int n = s.size();
        int i = 0,start=0;
        vector<string> factorization;
        while (i < n)
        {start=i;
            int j = i + 1, k = i;
            while (j < n && s[k] <= s[j])
            {
                if (s[k] < s[j])
                    k = i;
                else
                    k++;
                j++;
            }
            while (i <= k)
            {
                factorization.push_back(s.substr(i, j - k));
                i += j - k;
            }
        }
        return factorization;
    }
}; 
```
	
<b>vs code</b>
	
```
{
	"string":{
		"prefix":"StringFactorization",
		"body": [
			"class LyndonFactorization",
			"{",
			"public:",
			"    vector<string> duval(string const &s)",
			"    {",
			"        int n = s.size();",
			"        int i = 0,start=0;",
			"        vector<string> factorization;",
			"        while (i < n)",
			"        {start=i;",
			"            int j = i + 1, k = i;",
			"            while (j < n && s[k] <= s[j])",
			"            {",
			"                if (s[k] < s[j])",
			"                    k = i;",
			"                else",
			"                    k++;",
			"                j++;",
			"            }",
			"            while (i <= k)",
			"            {",
			"                factorization.push_back(s.substr(i, j - k));",
			"                i += j - k;",
			"            }",
			"        }",
			"        return factorization;",
			"    }",
			"};",
		],
	}

}
```
	
</details>


<details>
	<summary>tree diameter</summary>
	<b>Code</b>

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
            adj[a].pb(b);
            adj[b].pb(a);
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
        if(leaf==-1){
            cout<<0<<endl;
            return;
        }
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
	
<b>vs code</b>
	
```
{

	"global": {
		"prefix": "treeDiameter",
		"body": [
			"class TreeDiameter{",
			"public:",
			"    int n,leaf,diameter;",
			"    pair<int,int>diameterNodes,center;",
			"    vector<int>dis,parent;",
			"    vector<vector<int>>adj;",
			"    TreeDiameter(int _n){",
			"        n = _n;",
			"        diameter = 0;",
			"        leaf = -1;",
			"        adj.resize(n+1);",
			"        dis.resize(n+1,INT_MAX);",
			"        parent.resize(n+1);",
			"    }",
			"    void readTree(){",
			"        for(int i=1; i<n; i++){",
			"            int a,b;",
			"            cin>>a>>b;",
			"            adj[a].pb(b);",
			"            adj[b].pb(a);",
			"            if(adj[a].size()==1)leaf = a;",
			"            if(adj[b].size()==1)leaf = b;",
			"        }",
			"    }",
			"    void dfs(int node){",
			"        for(auto to:adj[node]){",
			"            if(dis[to] > dis[node]+1){",
			"                dis[to] = dis[node]+1;",
			"                parent[to] = node;",
			"                dfs(to);",
			"            }",
			"        }",
			"    }",
			"    void getMaxDisNode(int &a){",
			"        diameter = 0;",
			"        for(int i=1; i<=n; i++){",
			"            if(diameter < dis[i]){",
			"                diameter = dis[i];",
			"                a = i;",
			"            }",
			"        }",
			"    }",
			"    void findDiemater(){",
			"       if(leaf==-1){",
			"           cout<<0<<endl;",
			"           return;",
			"        }",
			"        dis[leaf] = 0;",
			"        parent[leaf] = leaf;",
			"        dfs(leaf);",
			"        getMaxDisNode(diameterNodes.first);",
			"        dis.assign(n+1,INT_MAX);",
			"        parent[diameterNodes.first] = diameterNodes.first;",
			"        dis[diameterNodes.first]=0;",
			"        dfs(diameterNodes.first);",
			"        getMaxDisNode(diameterNodes.second);",
			"    }",
			"    void findCenter(){",
			"        if(diameter&1){",
			"            int radius = diameter/2 +1;",
			"            int cur = diameterNodes.second;",
			"            while(dis[cur]!=radius){",
			"                cur = parent[cur];",
			"            }",
			"            center = {cur,parent[cur]};",
			"        }",
			"        else{",
			"            int radius = diameter/2;",
			"            int cur = diameterNodes.second;",
			"            while(dis[cur]!=radius){",
			"                cur = parent[cur];",
			"            }",
			"            center = {cur,cur};",
			"        }",
			"    }",
			"};",


		],
		"description": "help to find diameter and center of a tree",
	}
}	
```
	
</details>


<details>
	<summary>Sieve</summary>
	<b>Code</b>

```c++
long long prime_size=1e6+5;
vector<int> primes;
vector<bool> mark(prime_size);
void sieve(){
    long long i,j;
    mark[0]=mark[1]=1;
    for(i=4; i<prime_size; i+=2)mark[i]=1;
    for(i=3; i*i<=prime_size; i+=2){
        if(!mark[i]){
            for(j=i*i; j<=prime_size; j+=i*2)mark[j]=1;
        }
    }
    primes.pb(2);
    for(i=3; i<=prime_size; i+=2)if(!mark[i])primes.pb(i);
}
```
	
<b>vs code</b>
	
```
{
	"prime generate":{
		"prefix": "sieve",
		"body": [
			"ll prime_size=1e6+5;",
			"vi primes;",
			"vb mark(prime_size);",
			"void sieve(){",
			"    ll i,j;",
			"    mark[0]=mark[1]=1;",
			"    for(i=4; i<prime_size; i+=2)mark[i]=1;",
			"    for(i=3; i*i<=prime_size; i+=2){",
			"        if(!mark[i]){",
			"            for(j=i*i; j<=prime_size; j+=i*2)mark[j]=1;",
			"        }",
			"    }",
			"    primes.pb(2);",
			"    for(i=3; i<=prime_size; i+=2)if(!mark[i])primes.pb(i);",
			"}",

		],
		"description": "it is for find out prime",
	}
}
```
	
</details>



<details>
	<summary>Next one</summary>
	<b>Code</b>

```c++
	
```
	
<b>vs code</b>
	
```

```
	
</details>

