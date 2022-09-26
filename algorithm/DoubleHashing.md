<h2>Double hashing</h2>

```c++

#define mod1 2038074743
#define base1 117671
#define mod2 1000000007
#define base2 443
class Hash_table{
    public:
    string s;
    vector<long long> hash1,hash2,pow1,pow2;
    int n;
    Hash_table(string& s){
        this->s=s;
        n=s.size();
        hash1 = vector<long long>(n);
        hash2 = vector<long long>(n);
        pow1 = vector<long long>(n+1,1);
        pow2 = vector<long long>(n+1,1);
    }
    void gen_hash(){
        for(int i=1; i<=n; i++){
            pow1[i]=(pow1[i-1]*base1)%mod1;
            pow2[i]=(pow2[i-1]*base2)%mod2;
        }
        long long cur1=0,cur2=0;
        for(int i=0; i<n; i++){
            cur1 = (cur1*base1 + (s[i]-'a'+1))%mod1;
            cur2 = (cur2*base2 + (s[i]-'a'+1))%mod2;
            hash1[i]=cur1;
            hash2[i]=cur2;
        }
    }
    bool isMatched(int l1, int r1, int l2, int r2){
        if(r1<l1 or r2<l2 or r1-l1!=r2-l2)return false;
        long long len=r1-l1+1;
        long long h11 = (l1==0)?hash1[r1]:((hash1[r1]-hash1[l1-1]*pow1[len])%mod1+mod1)%mod1;
        long long h12 = (l1==0)?hash2[r1]:((hash2[r1]-hash2[l1-1]*pow2[len])%mod2+mod2)%mod2;
        long long h21 = (l2==0)?hash1[r2]:((hash1[r2]-hash1[l2-1]*pow1[len])%mod1+mod1)%mod1;
        long long h22 = (l2==0)?hash2[r2]:((hash2[r2]-hash2[l2-1]*pow2[len])%mod2+mod2)%mod2;
        if(h11==h21 and h12==h22)return true;
        return false;
    }
};
```
