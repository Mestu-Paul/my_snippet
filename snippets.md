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

