<h2>Decimal To Binary</h2>

```c++
void DecToBin(long long a, vector<bool>& bit){
    bit.clear();
    while(a){
        bit.push_back(a&1);
        a = a>>1;
    }
    reverse(bit.begin(),bit.end());
}
```
